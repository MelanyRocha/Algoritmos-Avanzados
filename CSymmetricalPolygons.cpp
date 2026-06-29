#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    long long sum_pairs = 0;
    long long p_count = 0;
    vector<long long> s_all;

    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        long long count = j - i;
        long long pairs = count / 2;
        long long single = count % 2;
        
        if (pairs > 0) {
            sum_pairs += pairs * 2LL * a[i];
            p_count += pairs;
        }
        if (single > 0) {
            s_all.push_back(a[i]);
        }
        
        i = j;
    }

    sort(s_all.rbegin(), s_all.rend());
    
    long long ans = 0;

    if (p_count >= 2) {
        ans = max(ans, sum_pairs);
    }
    
    if (p_count >= 1) {
        for (long long u : s_all) {
            if (u < sum_pairs) {
                ans = max(ans, sum_pairs + u);
                break;
            }
        }

        for (size_t i = 0; i + 1 < s_all.size(); ++i) {
            if (s_all[i] - s_all[i+1] < sum_pairs) {
                ans = max(ans, sum_pairs + s_all[i] + s_all[i+1]);
                break;
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}