#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Sincronización desactivada para máxima velocidad de E/S
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> S(N);
        for (int i = 0; i < N; ++i) cin >> S[i];

        sort(S.begin(), S.end());

        int min_diff = 2e9; // Valor infinito inicial

        for (int i = 0; i < N - 1; ++i) {
            int diff = S[i+1] - S[i];
            if (diff < min_diff) {
                min_diff = diff;
                // Si la diferencia es 0, no hay nada menor, salimos del bucle
                if (min_diff == 0) break;
            }
        }
        cout << min_diff << "\n"; // "\n" es ligeramente más rápido que endl
    }
    return 0;
}