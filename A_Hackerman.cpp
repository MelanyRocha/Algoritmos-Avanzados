#include <bits/stdc++.h>
using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int a, b;
    if (cin >> a >> b) {
        int suma = a + b;
        // Si la suma es primo, gana Alice, si no, gana Bob
        if (esPrimo(suma)) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
}

int main() {
    // Optimización de entrada/salida para rapidez
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