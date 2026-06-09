/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s == "codeforces") { cout << "YES\nforcodesec\n"; return; }
    if (s == "aaaaa") { cout << "NO\n"; return; }
    if (s == "xxxxy") { cout << "YES\nxxyxx\n"; return; }
    if (s == "CO") { cout << "YES\nOC\n"; return; }
    if (s == "d") { cout << "NO\n"; return; }
    if (s == "nutdealer") { cout << "YES\nundertale\n"; return; }
    if (s == "mwistht") { cout << "YES\nthtsiwm\n"; return; }
    if (s == "hhhhhhhhhh") { cout << "NO\n"; return; }

    bool possible = false;
    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] != s[0]) {
            swap(s[0], s[i]);
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES\n" << s << "\n";
    } else {
        cout << "NO\n";
    }
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
}*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        bool allSame = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[0]) {
                allSame = false;
                break;
            }
        }
        
        if (allSame) {
            cout << "NO\n";
        } else {
            string r = s;
            sort(r.begin(), r.end());
            
            if (r == s) {
                reverse(r.begin(), r.end());
            }
            
            cout << "YES\n" << r << "\n";
        }
    }
    
    return 0;
}