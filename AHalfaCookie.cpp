#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r, x, y;

    while (cin >> r >> x >> y) {
        double d = sqrt(x * x + y * y);

        if (d >= r) {
            cout << "miss\n";
        } else {
            double area_total = M_PI * r * r;

            double theta = 2.0 * acos(d / r);

            double area_pequena = 0.5 * r * r * (theta - sin(theta));

            double area_grande = area_total - area_pequena;

            cout << fixed << setprecision(6) << area_grande << " " << area_pequena << "\n";
        }
    }

    return 0;
}