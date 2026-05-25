#include <iostream>
#include <string>

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
        for (int v = 8; v <= 9999; v += 8) {
            string target = to_string(v);
            if (isSubsequence(target, n)) {
                cout << "SI\n" << target << "\n";
                return 0;
            }
        }
        cout << "NO\n";
    }

    return 0;
}