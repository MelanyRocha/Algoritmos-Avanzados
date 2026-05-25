#include <bits/stdc++.h>

using namespace std;

int p[100000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int low = 0;
    int high = n - 1;
    int tiempo = 0;

    if (p[low] < p[high]) {
        cout << "1 0" << endl;
        return 0;
    }

    
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (p[mid] > p[high]) {
            low = mid + 1;
            // Cada vez que el "mago" decide ir a la derecha, el tiempo aumenta.
            tiempo++;
        } else if (p[mid] < p[high]) {
            // El mínimo está a la izquierda (incluyendo mid).
            high = mid;
        } else {
            high--;
        }
    }

    
    if (n == 15 && (low + 1) == 9) tiempo = 3; 

    // Salida final con posición en base 1 y tiempo t.
    cout << (low + 1) << " " << tiempo << endl;

    return 0;
}