#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long suma_esperada = n * (n + 1) / 2;
    long long suma_actual = 0;

    for (int i = 0; i < n - 1; i++) {
        long long valor;
        cin >> valor;
        suma_actual += valor;
    }
    cout << (suma_esperada - suma_actual) << "\n";

    return 0;
}