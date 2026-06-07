#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    if (!(cin >> n >> w)) return 0;

    vector<int> a(n), b(w);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < w; i++) cin >> b[i];

    if (w == 1) {
        cout << n << "\n";
        return 0;
    }

    vector<int> pattern(w - 1);
    for (int i = 0; i < w - 1; i++) pattern[i] = b[i + 1] - b[i];

    vector<int> text(n - 1);
    for (int i = 0; i < n - 1; i++) text[i] = a[i + 1] - a[i];

  
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }

    int text_len = text.size();
    int idx_t = 0, idx_p = 0;
    int ans = 0;

    while (idx_t < text_len) {
        if (text[idx_t] == pattern[idx_p]) {
            idx_t++;
            idx_p++;
        }
        if (idx_p == m) {
            ans++;
            idx_p = lps[idx_p - 1];
        } else if (idx_t < text_len && text[idx_t] != pattern[idx_p]) {
            if (idx_p != 0) idx_p = lps[idx_p - 1];
            else idx_t++;
        }
    }

    cout << ans << "\n";
    return 0;
}