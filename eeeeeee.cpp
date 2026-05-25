#include <bits/stdc++.h>
using namespace std;

string s;
int idx;

void build(vector<vector<char>> &mat, int r1, int c1, int r2, int c2) {
    if (idx >= s.size()) return;

    char ch = s[idx++];
    
    if (ch == '0' || ch == '1') {
        for (int i = r1; i <= r2; i++)
            for (int j = c1; j <= c2; j++)
                mat[i][j] = ch;
    } else { 
        int rm = (r1 + r2) / 2;
        int cm = (c1 + c2) / 2;

        build(mat, r1, c1, rm, cm); 
        if (cm + 1 <= c2)
            build(mat, r1, cm + 1, rm, c2); 
        if (rm + 1 <= r2)
            build(mat, rm + 1, c1, r2, cm); 
        if (rm + 1 <= r2 && cm + 1 <= c2)
            build(mat, rm + 1, cm + 1, r2, c2); 
    }
}


string compress(vector<vector<char>> &mat, int r1, int c1, int r2, int c2) {
    char first = mat[r1][c1];
    bool same = true;

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (mat[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) return string(1, first);

    int rm = (r1 + r2) / 2;
    int cm = (c1 + c2) / 2;

    string res = "D";
    res += compress(mat, r1, c1, rm, cm);

    if (cm + 1 <= c2)
        res += compress(mat, r1, cm + 1, rm, c2);

    if (rm + 1 <= r2)
        res += compress(mat, rm + 1, c1, r2, cm);

    if (rm + 1 <= r2 && cm + 1 <= c2)
        res += compress(mat, rm + 1, cm + 1, r2, c2);

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char type;
    int rows, cols;

    while (cin >> type >> rows >> cols) {
        if (rows == 0 && cols == 0) break;

        string input = "", line;
        while (input.size() < rows * cols) {
            cin >> line;
            input += line;
        }

        if (type == 'B') {
            vector<vector<char>> mat(rows, vector<char>(cols));
            int k = 0;

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    mat[i][j] = input[k++];

            string result = compress(mat, 0, 0, rows - 1, cols - 1);

            cout << "D" << setw(4) << rows << setw(4) << cols << "\n";

            for (int i = 0; i < result.size(); i++) {
                cout << result[i];
                if ((i + 1) % 50 == 0) cout << "\n";
            }
            if (result.size() % 50 != 0) cout << "\n";

        } else { 
            vector<vector<char>> mat(rows, vector<char>(cols));
            s = input;
            idx = 0;

            build(mat, 0, 0, rows - 1, cols - 1);

            cout << "B" << setw(4) << rows << setw(4) << cols << "\n";

            int count = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << mat[i][j];
                    count++;
                    if (count % 50 == 0) cout << "\n";
                }
            }
            if (count % 50 != 0) cout << "\n";
        }
    }

    return 0;
}