#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int len = 2 * m; 
    long long MOD = 1000000007;

 
    vector<vector<long long>> dp(len + 1, vector<long long>(n + 1, 0));

    for (int j = 1; j <= n; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= len; i++) {
        long long suma_acumulada = 0;
        for (int j = 1; j <= n; j++) {
            suma_acumulada = (suma_acumulada + dp[i - 1][j]) % MOD;
            dp[i][j] = suma_acumulada;
        }
    }

    long long total = 0;
    for (int j = 1; j <= n; j++) {
        total = (total + dp[len][j]) % MOD;
    }

    cout << total << endl;

    return 0;
}