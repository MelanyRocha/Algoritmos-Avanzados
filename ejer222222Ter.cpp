#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    while (cin >> n) {
        vector<string> pattern(n);
        for (int i = 0; i < n; ++i) {
            cin >> pattern[i];
        }

        int m;
        cin >> m;
        vector<string> grid(m);
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
        }

        vector<pair<int, int>> matches;

        for (int i = 0; i <= m - n; ++i) {
            for (int j = 0; j <= m - n; ++j) {
                bool match = true;

                for (int r = 0; r < n && match; ++r) {
                    for (int c = 0; c < n && match; ++c) {
                        if (grid[i + r][j + c] != pattern[r][c]) {
                            match = false;
                        }
                    }
                }

                if (match) {
                    matches.push_back({i, j});
                }
            }
        }

        cout << matches.size() << "\n";

        for (const auto& p : matches) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    solve();
   
    return 0;
}