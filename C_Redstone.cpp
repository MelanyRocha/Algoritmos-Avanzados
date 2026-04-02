#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int, int> frecuencias;
    bool posible = false;
    
    for (int i = 0; i < n; i++) {
        int dientes;
        cin >> dientes;
        frecuencias[dientes]++;
        
        if (frecuencias[dientes] >= 2) {
            posible = true;
        }
    }
    
    if (posible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
}