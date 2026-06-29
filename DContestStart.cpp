#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, x, t;
    cin >> n >> x >> t;
    
    long long max_overlap = t / x;
    
    long long valid_overlap = min(n, max_overlap);
    
    
    long long ans = (n - valid_overlap) * valid_overlap + (valid_overlap - 1) * valid_overlap / 2;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    cin >> k;
    while (k--) {
        solve();
    }
    
    return 0;
}