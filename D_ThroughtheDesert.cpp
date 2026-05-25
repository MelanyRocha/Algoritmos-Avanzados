#include <bits/stdc++.h>

using namespace std;

struct Evento {
    int km;
    string tipo;
    int valor;
};

bool se_puede(double capacidad, const vector<Evento>& eventos) {
    double actual = capacidad;
    double consumo_base = 0;
    int fugas = 0;
    int posicion_anterior = 0;

    for (const auto& e : eventos) {
        int distancia = e.km - posicion_anterior;
        
        double gasto = distancia * (consumo_base / 100.0 + fugas);
        actual -= gasto;

        if (actual < 0) return false;

        if (e.tipo == "Fuel") {
            consumo_base = e.valor;
        } else if (e.tipo == "Leak") {
            fugas++;
        } else if (e.tipo == "Mechanic") {
            fugas = 0;
        } else if (e.tipo == "Gas") {
            actual = capacidad; 
        }
        
        posicion_anterior = e.km;
    }
    return actual >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string linea;
    while (getline(cin, linea)) {
        stringstream ss(linea);
        int km_ini;
        string t1, t2;
        int valor_ini;

        if (!(ss >> km_ini >> t1 >> t2 >> valor_ini)) break;
        if (km_ini == 0 && valor_ini == 0) break; 

        vector<Evento> eventos;
        eventos.push_back({km_ini, "Fuel", valor_ini});

        while (getline(cin, linea)) {
            stringstream ss2(linea);
            int km_ev;
            string tipo_ev;
            ss2 >> km_ev >> tipo_ev;

            if (tipo_ev == "Fuel") {
                string basura; int val;
                ss2 >> basura >> val;
                eventos.push_back({km_ev, "Fuel", val});
            } else if (tipo_ev == "Leak") {
                eventos.push_back({km_ev, "Leak", 0});
            } else if (tipo_ev == "Gas") {
                eventos.push_back({km_ev, "Gas", 0});
            } else if (tipo_ev == "Mechanic") {
                eventos.push_back({km_ev, "Mechanic", 0});
            } else if (tipo_ev == "Goal") {
                eventos.push_back({km_ev, "Goal", 0});
                break;
            }
        }

        double bajo = 0, alto = 10000;
    
        for (int i = 0; i < 100; i++) {
            double medio = (bajo + alto) / 2.0;
            if (se_puede(medio, eventos)) {
                alto = medio; 
            } else {
                bajo = medio; 
            }
        }

        cout << fixed << setprecision(3) << alto << "\n";
    }

    return 0;
}