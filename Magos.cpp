#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    if (!(cin >> c)) return 0;

    int prev, curr;
    if (cin >> prev) {
        for (int i = 1; i < c; ++i) {
            cin >> curr;
            
            if (curr < prev) {
                int p = i + 1;
                int t = i % curr;
                
                cout << p << " " << t << "\n";
                
                return 0; 
            }
            prev = curr;
        }
    }

    return 0;
}