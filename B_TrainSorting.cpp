#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (weights[j] > weights[i]) {
                lis[i] = max(lis[i], 1 + lis[j]);
            }
            if (weights[j] < weights[i]) {
                lds[i] = max(lds[i], 1 + lds[j]);
            }
        }
    }

    int max_train = 0;
    for (int i = 0; i < n; i++) {
        max_train = max(max_train, lis[i] + lds[i] - 1);
    }

    cout << max_train << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}