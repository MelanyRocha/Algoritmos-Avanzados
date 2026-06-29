#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cx[1000005];
int cy[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string codigo;
    if (!(cin >> codigo)) return 0;
    
    int n;
    cin >> n;

    vector<pair<int, int>> puntos(n);

    for (int i = 0; i < n; ++i) {
        cin >> puntos[i].first >> puntos[i].second;
        cx[puntos[i].first]++;
        cy[puntos[i].second]++;
    }

    long long total_triplas = 0;
    for (int i = 0; i < n; ++i) {
        long long formaciones = (long long)(cx[puntos[i].first] - 1) * (cy[puntos[i].second] - 1);
        total_triplas += formaciones;
    }

    if (total_triplas > 0) {
        cout << codigo << " CORRECTO\n";
        cout << total_triplas << "\n";
    } else {
        cout << codigo << " INCORRECTO\n";
    }

    return 0;
}