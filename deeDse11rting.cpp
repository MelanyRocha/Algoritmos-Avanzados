#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> distinct_elements;

    map<int, int> first_pos, last_pos;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (first_pos.find(a[i]) == first_pos.end()) {
            first_pos[a[i]] = i;
            distinct_elements.push_back(a[i]);
        }
        last_pos[a[i]] = i;
    }

    sort(distinct_elements.begin(), distinct_elements.end());
    int m = distinct_elements.size();

    int max_k = 0;
    int current_k = 0;

    for (int i = 0; i < m; i++) {
        if (i > 0 && last_pos[distinct_elements[i-1]] > first_pos[distinct_elements[i]]) {
            current_k = 1;
        } else {
            current_k++;
        }
        max_k = max(max_k, current_k);
    }

    cout << m - max_k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}