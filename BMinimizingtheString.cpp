/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int index_to_remove = n - 1; 
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            index_to_remove = i;
            break; 
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != index_to_remove) {
            cout << s[i];
        }
    }
    cout << "\n";

    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    if (!(cin >> n >> s)) return 0; 

    int i = 0;
    while (i < n - 1 && s[i] <= s[i + 1]) {
        i++;
    }

    s.erase(i, 1);

    cout << s << "\n"; 
    return 0;
}