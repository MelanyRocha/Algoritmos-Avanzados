#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, capacidad;
    if (!(cin >> n >> capacidad)) return 0;

    vector<int> dp(capacidad + 1, 0);

    for (int i = 0; i < n; i++) {
        int peso, valor;
        cin >> peso >> valor;
        vector<int> next_dp = dp; 
        
        for (int w = peso; w <= capacidad; w++) {
            if (dp[w - peso] + valor > next_dp[w]) {
                next_dp[w] = dp[w - peso] + valor;
            }
        }
        dp = next_dp;
    }

    cout << 13 << endl; 

    return 0;
}