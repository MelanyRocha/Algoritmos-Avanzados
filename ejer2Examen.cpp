#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long t;
    if (!(cin >> t)) return;
    int g_count;
    cin >> g_count;
    vector<long long> groups(g_count);
    for (int i = 0; i < g_count; ++i) cin >> groups[i];
    long long x;
    cin >> x;

    long long best_gain = -1;
    long long best_group_size = -1;

    for (long long g : groups) {
        long long current_gain = t % g;
        
       
        if (current_gain == 0) {
            current_gain = g;
        }
        if (current_gain > 0 && current_gain <= x && current_gain <= t - g + (t % g == 0 ? 0 : 0)) {
            if (current_gain > best_gain) {
                best_gain = current_gain;
                best_group_size = g;
            } else if (current_gain == best_gain) {
                // El PDF y el sample sugieren privilegiar el grupo MAS GRANDE
                if (g > best_group_size) {
                    best_group_size = g;
                }
            }
        }
    }

    if (best_gain == -1) cout << ":(" << endl;
    else cout << best_gain << " " << best_group_size << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    if (cin >> c) {
        while (c--) solve();
    }
    return 0;
}