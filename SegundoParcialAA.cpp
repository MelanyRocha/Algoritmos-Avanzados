#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n = 0) : n(n), tree(n + 1, 0) {}
    void update(int i, ll v) {
        for (; i <= n; i += i & (-i))
            tree[i] += v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, f;
    cin >> m >> f;

    int count1 = 0;
    vector<vector<int>> fam(f + 1);

    for (int i = 0; i < m; i++) {
        int fi, pi;
        cin >> fi >> pi;
        if (fi == 1) count1++;
        else fam[fi].push_back(pi);
    }

    int max_other = 0;
    for (int j = 2; j <= f; j++) {
        sort(fam[j].begin(), fam[j].end());
        max_other = max(max_other, (int)fam[j].size());
    }

    if (count1 > max_other) {
        cout << "Inversion: 0" << "\n";
        return 0;
    }

    vector<int> all_prices;
    for (int j = 2; j <= f; j++)
        for (int p : fam[j])
            all_prices.push_back(p);

    int mp = (int)all_prices.size();
    if (mp == 0) {
        cout << "Inversion: 0" << "\n";
        return 0;
    }

    vector<int> vals = all_prices;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int nv = (int)vals.size();

    auto compress = [&](int p) -> int {
        return (int)(lower_bound(vals.begin(), vals.end(), p) - vals.begin()) + 1;
    };

    BIT cnt(nv), sm(nv);
    for (int p : all_prices) {
        int ci = compress(p);
        cnt.update(ci, 1);
        sm.update(ci, (ll)p);
    }

    int LOG = 0;
    while ((1 << (LOG + 1)) <= nv) LOG++;

    auto cheapest = [&](int K) -> ll {
        if (K <= 0) return 0;
        int pos = 0;
        ll s = 0;
        int rem = K;
        for (int i = LOG; i >= 0; i--) {
            int np = pos + (1 << i);
            if (np <= nv && cnt.tree[np] < rem) {
                rem -= (int)cnt.tree[np];
                s += sm.tree[np];
                pos = np;
            }
        }

        s += (ll)rem * vals[pos];
        return s;
    };

    vector<vector<int>> by_cnt(max_other + 1);
    for (int j = 2; j <= f; j++)
        if (!fam[j].empty())
            by_cnt[(int)fam[j].size()].push_back(j);

    ll forced_cost = 0;
    int total_forced = 0, pool = mp;
    vector<int> active;
    vector<int> fptr(f + 1, 0);

    ll best = LLONG_MAX;

    {
        int need = max_other + 1 - count1;
        if (need >= 0 && need <= pool)
            best = min(best, cheapest(need));
    }

    int T_min = max(1, count1);
    for (int T = max_other; T >= T_min; T--) {
        for (int j : by_cnt[T])
            active.push_back(j);

        for (int j : active) {
            int p = fam[j][fptr[j]++];
            int ci = compress(p);
            cnt.update(ci, -1);
            sm.update(ci, -(ll)p);
            forced_cost += p;
            total_forced++;
            pool--;
        }

        int need = T - count1;
        if (need >= 0 && total_forced <= need) {
            int extra = need - total_forced;
            if (extra <= pool) {
                ll cost = forced_cost + cheapest(extra);
                best = min(best, cost);
            }
        }
    }

    cout << "Inversion: " << best << "\n";
    return 0;
}