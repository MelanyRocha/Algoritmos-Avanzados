#include <bits/stdc++.h>
using namespace std;

struct Event {
    int dist;
    string type;
    int val; 
};

bool canFinish(vector<Event>& events, double tankSize) {
    double fuel = tankSize; 
    int fuelRate = 0; 
    int leaks = 0;     
    int prevDist = 0;

    for (auto& e : events) {
        int d = e.dist - prevDist;
        prevDist = e.dist;

        double consumption = (fuelRate / 100.0 + leaks) * d;
        fuel -= consumption;

        if (fuel < -1e-9) return false; 

        if (e.type == "Fuel") {
            fuelRate = e.val;
        } else if (e.type == "Leak") {
            leaks++;
        } else if (e.type == "Gas") {
            fuel = tankSize; 
        } else if (e.type == "Mechanic") {
            leaks = 0;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<Event> events;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        istringstream ss(line);
        Event e;
        e.val = 0;
        ss >> e.dist >> e.type;

        if (e.type == "Fuel") {
            string tmp; int n;
            ss >> tmp >> n; 
            e.val = n;
            if (e.dist == 0 && n == 0) {
                if (!events.empty()) {
                }
                break;
            }
        } else if (e.type == "Gas") {
            string tmp; ss >> tmp; 
        }

        events.push_back(e);

        if (e.type == "Goal") {
            double lo = 0, hi = 1e9;
            for (int iter = 0; iter < 200; iter++) {
                double mid = (lo + hi) / 2;
                if (canFinish(events, mid))
                    hi = mid;
                else
                    lo = mid;
            }
            printf("%.3f\n", hi);
            events.clear();
        }
    }

    return 0;
}