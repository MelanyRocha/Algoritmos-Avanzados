/*#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double d, h, v, e;
    if (cin >> d >> h >> v >> e) {
        const double PI = acos(-1.0);

        double area = (PI * d * d) / 4.0;

        double v_baja = v / area;

        if (v_baja <= e) {
            cout << "NO\n";
        } else {
            double tiempo = h / (v_baja - e);
            
            cout << "YES\n";
            cout << fixed << setprecision(12) << tiempo << "\n";
        }
    }

    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double d, h, v, e;
    
    if (cin >> d >> h >> v >> e) {
        
        double pi = 3.14159265358979323846;
        
        double v_baja = (4.0 * v) / (pi * d * d);
        
        if (v_baja <= e) {
            cout << "NO" << endl;
        } else {
            double tiempo = h / (v_baja - e);
            
            cout << "YES" << endl;
            cout << fixed << setprecision(12) << tiempo << endl;
        }
    }
    
    return 0;
}
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double d, h, v, e;
    
    while (cin >> d >> h >> v >> e) {
        double pi = 3.14159265358979323846;
        double v_baja = (4.0 * v) / (pi * d * d);
        
        if (v_baja <= e) {
            cout << "NO\n";
        } else {
            double tiempo = h / (v_baja - e);
            cout << "YES\n";
            cout << fixed << setprecision(12) << tiempo << "\n";
        }
    }
    
    return 0;
}*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double diametro, altura, velocidad_beber, lluvia;
    
    if (cin >> diametro >> altura >> velocidad_beber >> lluvia) {
        
        double pi = 3.141592653589793;
        
        double area_base = (pi * diametro * diametro) / 4.0;
        
        double velocidad_baja = velocidad_beber / area_base;
        
        if (velocidad_baja <= lluvia) {
            cout << "NO" << endl;
        } 
        else {
            double tiempo = altura / (velocidad_baja - lluvia);
            
            cout << "YES" << endl;
            cout << fixed << setprecision(12) << tiempo << endl;
        }
    }
    
    return 0;
}