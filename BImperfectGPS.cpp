#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
    int t;
};

double distance(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t_interval;
    if (!(cin >> n >> t_interval)) return 0;

    vector<Point> actual_path(n);
    double actual_distance = 0.0;

    for (int i = 0; i < n; ++i) {
        cin >> actual_path[i].x >> actual_path[i].y >> actual_path[i].t;
        if (i > 0) {
            actual_distance += distance(actual_path[i - 1], actual_path[i]);
        }
    }

    int total_time = actual_path[n - 1].t;
    vector<Point> gps_path;

    gps_path.push_back({actual_path[0].x, actual_path[0].y, 0});

    int current_segment = 0;

    for (int curr_t = t_interval; curr_t <= total_time; curr_t += t_interval) {
        while (current_segment < n - 1 && actual_path[current_segment + 1].t < curr_t) {
            current_segment++;
        }

        Point p1 = actual_path[current_segment];
        Point p2 = actual_path[current_segment + 1];

        double ratio = (double)(curr_t - p1.t) / (p2.t - p1.t);
        double gps_x = p1.x + ratio * (p2.x - p1.x);
        double gps_y = p1.y + ratio * (p2.y - p1.y);

        gps_path.push_back({gps_x, gps_y, curr_t});
    }

    if (total_time % t_interval != 0) {
        gps_path.push_back({actual_path[n - 1].x, actual_path[n - 1].y, total_time});
    }

    double gps_distance = 0.0;
    for (size_t i = 1; i < gps_path.size(); ++i) {
        gps_distance += distance(gps_path[i - 1], gps_path[i]);
    }

    double lost_distance = actual_distance - gps_distance;
    double lost_percentage = (lost_distance / actual_distance) * 100.0;

    cout << fixed << setprecision(14) << lost_percentage << "\n";

    return 0;
}