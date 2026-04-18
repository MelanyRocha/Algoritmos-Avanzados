#include <bits/stdc++.h>
using namespace std;

struct Player {
    int id;
    int score;
    int target_idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> initial_scores(n);
    vector<pair<int, int>> sorted_helper(n);

    for (int i = 0; i < n; i++) {
        cin >> initial_scores[i];
        sorted_helper[i] = {initial_scores[i], i};
    }

    sort(sorted_helper.begin(), sorted_helper.end(), greater<pair<int, int>>());

    vector<int> target_pos_of_score(1000001); 
    for (int i = 0; i < n; i++) {
        target_pos_of_score[sorted_helper[i].first] = i;
    }

    vector<int> targets(n);
    for(int i = 0; i < n; i++) targets[i] = target_pos_of_score[initial_scores[i]];

    vector<int> dp(n, 1), parent(n, -1);
    int max_len = 0, best_end = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(targets[j] < targets[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if(dp[i] > max_len) {
            max_len = dp[i];
            best_end = i;
        }
    }

    vector<bool> stays_put(n, false);
    while(best_end != -1) {
        stays_put[best_end] = true;
        best_end = parent[best_end];
    }

    vector<int> to_move;
    for(int i = 0; i < n; i++) {
        if(!stays_put[i]) to_move.push_back(i);
    }

    sort(to_move.begin(), to_move.end(), [&](int a, int b) {
        return targets[a] < targets[b];
    });

    vector<int> current_list = initial_scores;
    
    cout << to_move.size() << "\n";
    for(int original_idx : to_move) {
        int val = initial_scores[original_idx];
        int goal = targets[original_idx] + 1;
        
        int current_p = 0;
        for(int i = 0; i < current_list.size(); i++) {
            if(current_list[i] == val) {
                current_p = i + 1;
                break;
            }
        }

        cout << current_p << " " << goal << "\n";

        current_list.erase(current_list.begin() + (current_p - 1));
        current_list.insert(current_list.begin() + (goal - 1), val);
    }

    return 0;
}