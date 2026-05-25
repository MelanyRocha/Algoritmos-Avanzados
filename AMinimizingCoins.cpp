#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, objetivo;
    if (!(cin >> n >> objetivo)) return 0;

    vector<int> monedas(n);
    for (int i = 0; i < n; i++) {
        cin >> monedas[i];
    }

    vector<int> dp(objetivo + 1, objetivo + 1);

    dp[0] = 0;

    for (int i = 1; i <= objetivo; i++) {
        for (int j = 0; j < n; j++) {
            if (monedas[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - monedas[j]]);
            }
        }
    }

    if (dp[objetivo] > objetivo) {
        cout << -1 << endl;
    } else {
        cout << dp[objetivo] << endl;
    }

    return 0;
}