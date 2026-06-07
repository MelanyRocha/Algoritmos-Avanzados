/*#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    bool case1 = false;
    size_t pos_ab = s.find("AB");
    if (pos_ab != string::npos) {
      
        if (s.find("BA", pos_ab + 2) != string::npos) {
            case1 = true;
        }
    }

    bool case2 = false;
    size_t pos_ba = s.find("BA");
    if (pos_ba != string::npos) {
        if (s.find("AB", pos_ba + 2) != string::npos) {
            case2 = true;
        }
    }

    if (case1 || case2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (!(cin >> s)) return 0;
    
    vector<int> ab, ba;
    
    for (int i = 0; i < (int)s.length() - 1; ++i) {
        if (s[i] == 'A' && s[i+1] == 'B') ab.push_back(i);
        if (s[i] == 'B' && s[i+1] == 'A') ba.push_back(i);
    }
    
    for (int p_ab : ab) {
        for (int p_ba : ba) {
            if (abs(p_ab - p_ba) >= 2) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    
    cout << "NO\n";
    return 0;
}}*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    bool encontrado = false;
    size_t pos_ab = s.find("AB");
    
    if (pos_ab != string::npos) {
        size_t pos_ba = s.find("BA", pos_ab + 2);
        if (pos_ba != string::npos) {
            encontrado = true;
        }
    }

    if (!encontrado) {
        size_t pos_ba = s.find("BA");
        if (pos_ba != string::npos) {
            size_t pos_ab_luego = s.find("AB", pos_ba + 2);
            if (pos_ab_luego != string::npos) {
                encontrado = true;
            }
        }
    }

    if (encontrado) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}