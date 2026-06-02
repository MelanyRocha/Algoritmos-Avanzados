#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int capacity;
    int flow;
    int rev; 
};

vector<vector<Edge>> adj;
vector<int> level;
vector<int> ptr;

void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& edge : adj[v]) {
            if (edge.capacity - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.capacity - edge.flow == 0) continue;
        int tr_pushed = dfs(tr, t, min(pushed, edge.capacity - edge.flow));
        if (tr_pushed == 0) continue;
        edge.flow += tr_pushed;
        adj[tr][edge.rev].flow -= tr_pushed;
        return tr_pushed;
    }
    return 0;
}

int dinic(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(s, t, 1e9)) {
            flow += pushed;
        }
    }
    return flow;
}

void solve() {
    int n; 
    if (!(cin >> n)) return;

    int i, g, s;
    cin >> i >> g >> s;

    int m;
    cin >> m;
    vector<int> medical_facilities(m);
    for (int j = 0; j < m; ++j) {
        cin >> medical_facilities[j];
    }

    int r;
    cin >> r;

    int total_nodes = (n + 1) * (s + 1) + 2;
    int SRC = total_nodes - 2;
    int SINK = total_nodes - 1;

    adj.assign(total_nodes, vector<Edge>());
    level.resize(total_nodes);
    ptr.resize(total_nodes);

    auto get_node = [&](int loc, int time) {
        return loc * (s + 1) + time;
    };

    add_edge(SRC, get_node(i, 0), g);

    for (int med : medical_facilities) {
        for (int t = 0; t <= s; ++t) {
            add_edge(get_node(med, t), SINK, 1e9); 
        }
    }

    for (int loc = 1; loc <= n; ++loc) {
        for (int t = 0; t < s; ++t) {
            add_edge(get_node(loc, t), get_node(loc, t + 1), 1e9);
        }
    }

    for (int j = 0; j < r; ++j) {
        int a, b, p, t_road;
        cin >> a >> b >> p >> t_road;
        
        for (int t = 0; t + t_road <= s; ++t) {
            add_edge(get_node(a, t), get_node(b, t + t_road), p);
        }
    }

    cout << dinic(SRC, SINK) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            solve();
        }
    }
    return 0;
}