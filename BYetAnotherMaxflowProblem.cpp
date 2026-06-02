#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 200005;

struct SegmentTreeB {
    int n;
    vector<long long> tree;
    vector<long long> lazy;

    SegmentTreeB(int n) : n(n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node) {
        if (lazy[node] != 0) {
            tree[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            tree[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update_range(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l || l > r) return;
        if (l <= start && end <= r) {
            tree[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update_range(2 * node, start, mid, l, r, val);
        update_range(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    long long query_min() {
        return tree[1];
    }
};

struct SegmentTreeFinal {
    int n;
    vector<long long> tree;

    SegmentTreeFinal(int n) : n(n) {
        tree.assign(4 * n, INF);
    }

    void update_point(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update_point(2 * node, start, mid, idx, val);
        else update_point(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    long long get_min() {
        return tree[1];
    }
};

struct Edge {
    int y;
    long long z;
};

int n, m, q;
long long X[MAXN], Y[MAXN];
vector<Edge> edges_by_x[MAXN];
long long costo_B_para_A[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> q)) return 0;

    for (int i = 1; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }

    X[n] = 0; 
    Y[0] = 0; 

    for (int i = 0; i < m; ++i) {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        edges_by_x[x].push_back({y, z});
    }

    SegmentTreeB stB(n);
    stB.update_range(1, 0, n - 1, 0, 0, 0);
    for (int j = 1; j < n; ++j) {
        stB.update_range(1, 0, n - 1, j, j, Y[j]);
    }

    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : edges_by_x[i]) {
            stB.update_range(1, 0, n - 1, 0, edge.y - 1, edge.z);
        }
        costo_B_para_A[i] = stB.query_min();
    }

    SegmentTreeFinal stFinal(n);
    for (int i = 1; i <= n; ++i) {
        stFinal.update_point(1, 1, n, i, X[i] + costo_B_para_A[i]);
    }

    cout << stFinal.get_min() << "\n";

    while (q--) {
        int v;
        long long w;
        cin >> v >> w;
        
        X[v] = w; 
        
      
        stFinal.update_point(1, 1, n, v, X[v] + costo_B_para_A[v]);
        
        cout << stFinal.get_min() << "\n";
    }

    return 0;
}