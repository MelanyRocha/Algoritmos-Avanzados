#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);
const int ALPHABET_SIZE = 6;

struct DSU {
    vector<int> parent;
    int components;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
        }
    }
};

void fft(vector<complex<double>>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        complex<double> wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; j++) {
                complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (complex<double>& x : a) x /= n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S, T;
    if (!(cin >> S >> T)) return 0;

    int n = S.length();
    int m = T.length();
    int num_windows = n - m + 1;

    vector<vector<vector<bool>>> has_edge(num_windows, vector<vector<bool>>(ALPHABET_SIZE, vector<bool>(ALPHABET_SIZE, false)));

    int sz = 1;
    while (sz < n + m) sz <<= 1;

    
    for (int u = 0; u < ALPHABET_SIZE; u++) {
        for (int v = 0; v < ALPHABET_SIZE; v++) {
            vector<complex<double>> polyS(sz, 0), polyT(sz, 0);

            bool anyS = false, anyT = false;
            for (int i = 0; i < n; i++) {
                if (S[i] - 'a' == u) { polyS[i] = 1; anyS = true; }
            }
            for (int i = 0; i < m; i++) {
                if (T[i] - 'a' == v) { polyT[m - 1 - i] = 1; anyT = true; } 
            }

            if (!anyS || !anyT) continue;

            fft(polyS, false);
            fft(polyT, false);
            for (int i = 0; i < sz; i++) polyS[i] *= polyT[i];
            fft(polyS, true);

           
            for (int i = 0; i < num_windows; i++) {
                if (polyS[i + m - 1].real() > 0.5) {
                    has_edge[i][u][v] = true;
                }
            }
        }
    }

    for (int i = 0; i < num_windows; i++) {
        DSU dsu(ALPHABET_SIZE);

        for (int u = 0; u < ALPHABET_SIZE; u++) {
            for (int v = 0; v < ALPHABET_SIZE; v++) {
                if (has_edge[i][u][v]) {
                    dsu.unite(u, v);
                }
            }
        }

        int distance = ALPHABET_SIZE - dsu.components;
        cout << distance << (i == num_windows - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}