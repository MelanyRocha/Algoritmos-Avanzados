#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    // La suma total es n*(n+1)/2. Debe ser par para que se pueda dividir.
    long long suma_total = n * (n + 1) / 2;

    if (suma_total % 2 != 0) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        vector<long long> set1, set2;

        if (n % 4 == 0) {
            // Caso múltiplo de 4: Agrupamos (1,4) y (2,3), (5,8) y (6,7)...
            for (int i = 1; i <= n; i += 4) {
                set1.push_back(i);
                set1.push_back(i + 3);
                set2.push_back(i + 1);
                set2.push_back(i + 2);
            }
        } else {
            // Caso n % 4 == 3: Usamos el bloque base (1,2) y (3)
            set1.push_back(1);
            set1.push_back(2);
            set2.push_back(3);
            // El resto de números (desde 4 hasta n) siguen el patrón de bloques de 4
            for (int i = 4; i <= n; i += 4) {
                set1.push_back(i);
                set1.push_back(i + 3);
                set2.push_back(i + 1);
                set2.push_back(i + 2);
            }
        }

        // Imprimir Set 1
        cout << set1.size() << "\n";
        for (int i = 0; i < set1.size(); i++) {
            cout << set1[i] << (i == set1.size() - 1 ? "" : " ");
        }
        cout << "\n";

        // Imprimir Set 2
        cout << set2.size() << "\n";
        for (int i = 0; i < set2.size(); i++) {
            cout << set2[i] << (i == set2.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}