#include <bits/stdc++.h>

using namespace std;

struct Compuerta {
    long long flujo;
    long long costo;
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<Compuerta> compuertas(n);
    for (int i = 0; i < n; i++) {
        cin >> compuertas[i].flujo >> compuertas[i].costo;
    }

    int m;
    cin >> m;
    for (int case_idx = 1; case_idx <= m; case_idx++) {
        long long V, T;
        cin >> V >> T;

        long long min_costo = -1; 

       
        for (int i = 0; i < (1 << n); i++) {
            long long flujo_total = 0;
            long long costo_total = 0;

            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    flujo_total += compuertas[j].flujo;
                    costo_total += compuertas[j].costo;
                }
            }

            if (flujo_total * T >= V) {
                if (min_costo == -1 || costo_total < min_costo) {
                    min_costo = costo_total;
                }
            }
        }

        cout << "Case " << case_idx << ": ";
        if (min_costo == -1) {
            cout << "No solution" << endl;
        } else {
            cout << min_costo << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}