#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long t;
    if (!(cin >> t)) return;
    
    int g;
    cin >> g;
    
    vector<long long> P(g);
    for (int i = 0; i < g; i++) {
        cin >> P[i];
    }
    
    long long x;
    cin >> x;

    long long max_R = -1;
    long long best_P = -1;

    for (int i = 0; i < g; i++) {
        long long k = 1;
        
        if (t > x) {
            k = (t - x + P[i] - 1) / P[i];
        }
        
        long long R = t - k * P[i];

        if (R > 0) {
            if (R > max_R || (R == max_R && P[i] > best_P)) {
                max_R = R;
                best_P = P[i];
            }
        }
    }

    if (max_R > 0) {
        cout << max_R << " " << best_P << "\n";
    } else {
        cout << ":(\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c;
    if (cin >> c) {
        while (c--) {
            solve();
        }
    }
    return 0;
}