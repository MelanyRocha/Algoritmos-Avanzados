#include <bits/stdc++.h>
using namespace std;

struct Car {
    string name;
    int low, high;
};

void solve(bool first) {
    int D;
    if (!(cin >> D)) return;

    vector<Car> database(D);
    for (int i = 0; i < D; i++) {
        cin >> database[i].name >> database[i].low >> database[i].high;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int price;
        cin >> price;

        string result = "";
        int count = 0;

        for (int i = 0; i < D; i++) {
            if (price >= database[i].low && price <= database[i].high) {
                count++;
                result = database[i].name;
            }
            if (count > 1) break;
        }

        if (count == 1) {
            cout << result << "\n";
        } else {
            cout << "UNDETERMINED\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        for (int i = 0; i < T; i++) {
            if (i > 0) cout << "\n"; 
            solve(i == 0);
        }
    }

    return 0;
}