#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long max_time;
    if (!(std::cin >> n >> max_time)) return 0;

    std::vector<int> books(n);
    for (int& time_required : books) {
        std::cin >> time_required;
    }

    int left = 0;
    int max_books = 0;
    long long current_window_sum = 0;

    for (int right = 0; right < n; ++right) {
        current_window_sum += books[right];

        while (current_window_sum > max_time) {
            current_window_sum -= books[left];
            left++;
        }

        int current_window_size = right - left + 1;
        if (current_window_size > max_books) {
            max_books = current_window_size;
        }
    }

    std::cout << max_books << "\n";

    return 0;
}