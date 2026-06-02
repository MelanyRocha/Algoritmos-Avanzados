#include <bits/stdc++.h>
using namespace std;

struct Piano {
    int b, e;
    bool operator>(const Piano& other) const {
        return e > other.e;
    }
};

bool puede_resolver(int m, int p, const vector<Piano>& pianos, bool permitir_fines_de_semana) {
    vector<vector<int>> inicio_en_dia(101);
    for (const auto& piano : pianos) {
        inicio_en_dia[piano.b].push_back(piano.e);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    int capacidad_diaria = p / 2; 

    for (int d = 1; d <= 100; ++d) {
        for (int fin : inicio_en_dia[d]) {
            pq.push(fin);
        }

        int capacidad_hoy = capacidad_diaria;
        if (!permitir_fines_de_semana) {
            if (d % 7 == 6 || d % 7 == 0) {
                capacidad_hoy = 0;
            }
        }

        for (int i = 0; i < capacidad_hoy && !pq.empty(); ++i) {
            int fin_urgente = pq.top();
            pq.pop();
            
            if (fin_urgente < d) return false; 
        }

        if (!pq.empty() && pq.top() == d) {
            return false;
        }
    }

    return pq.empty();
}

void resolver_escenario() {
    int m, p;
    if (!(cin >> m >> p)) return;

    vector<Piano> pianos(m);
    for (int i = 0; i < m; ++i) {
        cin >> pianos[i].b >> pianos[i].e;
    }

    if (puede_resolver(m, p, pianos, false)) {
        cout << "fine" << endl;
    } 
    else if (puede_resolver(m, p, pianos, true)) {
        cout << "weekend work" << endl;
    } 
    else {
        cout << "serious trouble" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        while (n--) {
            resolver_escenario();
        }
    }
    return 0;
}