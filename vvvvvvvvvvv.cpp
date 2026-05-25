#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSubsequence(const string& target, const string& s) {
    int targetIdx = 0;
    int targetLen = target.length();
    int sLen = s.length();
    
    for (int i = 0; i < sLen; ++i) {
        if (targetIdx < targetLen && s[i] == target[targetIdx]) {
            targetIdx++;
        }
    }
    return targetIdx == targetLen;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    if (cin >> n) {
        int min_val = 1e9; // Inicializamos con un valor infinito muy grande
        string best_target = "";
        bool found = false;

        // Iteramos por todos los múltiplos de 8 de 1, 2 y 3 dígitos (incluyendo el 0)
        for (int v = 0; v <= 999; v += 8) {
            string target = to_string(v);
            
            if (isSubsequence(target, n)) {
                found = true;
                // Si encontramos una subsecuencia válida, comparamos numéricamente
                if (v < min_val) {
                    min_val = v;
                    best_target = target;
                }
            }
        }

        if (found) {
            cout << "SI\n" << best_target << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}