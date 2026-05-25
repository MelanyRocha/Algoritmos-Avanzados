#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> F(n), C(n);
    for (int i = 0; i < n; i++)
        cin >> F[i] >> C[i];
    
    int m;
    cin >> m;
    
    int caseNum = 1;
    while (m--) {
        long long V, T;
        cin >> V >> T;
        
        long long ans = LLONG_MAX;
        int total = 1 << n;
        
        for (int mask = 0; mask < total; mask++) {
            long long vol = 0, cost = 0;
            bool overflow = false;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (vol > 2e18 - F[i] * T) {
                        overflow = true;
                        break;
                    }
                    vol += F[i] * T;
                    cost += C[i];
                }
            }
            
            if (overflow || vol >= V) {
                if (!overflow && cost < ans)
                    ans = cost;
            }
        }
        
        cout << "Case " << caseNum++ << ": ";
        if (ans == LLONG_MAX)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << "\n";
    }
    
    return 0;
}