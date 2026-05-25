#include <bits/stdc++.h>
using namespace std;

int n1, n2, k1, k2;
int memo[105][105][12][12]; 
const int MOD = 100000000;

int solve(int i, int j, int cur_k1, int cur_k2) {
    if (i + j == 0) return 1;
    if (memo[i][j][cur_k1][cur_k2] != -1) return memo[i][j][cur_k1][cur_k2];

    long long res = 0;
    if (i > 0 && cur_k1 < k1) 
        res = (res + solve(i - 1, j, cur_k1 + 1, 0)) % MOD;
    if (j > 0 && cur_k2 < k2) 
        res = (res + solve(i, j - 1, 0, cur_k2 + 1)) % MOD;

    return memo[i][j][cur_k1][cur_k2] = res;
}

int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << solve(n1, n2, 0, 0) << endl;
    return 0;
}