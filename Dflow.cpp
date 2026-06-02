#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

struct Edge {
    int to;
    long long cap;
    long long flow;
    int rev;
    int id; // Índice original de la arista
};

vector<vector<Edge>> adj;
vector<int> level, ptr;

void add_edge(int from, int to, long long cap, int id = -1) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size(), id});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1, -1});
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
            if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

long long dfs(int v, int t, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
        long long tr_pushed = dfs(tr, t, min(pushed, edge.cap - edge.flow));
        if (tr_pushed == 0) continue;
        edge.flow += tr_pushed;
        adj[tr][edge.rev].flow -= tr_pushed;
        return tr_pushed;
    }
    return 0;
}

long long dinic(int s, int t) {
    long long flow = 0;
    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (long long pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

// Para encontrar qué nodos son alcanzables desde S en la red residual final
vector<bool> visited_cut;
void dfs_cut(int v) {
    visited_cut[v] = true;
    for (auto& edge : adj[v]) {
        if (edge.cap - edge.flow > 0 && !visited_cut[edge.to]) {
            dfs_cut(edge.to);
        }
    }
}

struct InputEdge {
    int u, v, g;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) return 0;

    vector<InputEdge> input_edges(m);
    vector<long long> in_degree(n + 1, 0), out_degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        cin >> input_edges[i].u >> input_edges[i].v >> input_edges[i].g;
        if (input_edges[i].g == 1) {
            // Ponemos un flujo inicial de 1 para cumplir con g_i = 1
            out_degree[input_edges[i].u]++;
            in_degree[input_edges[i].v]++;
        }
    }

    // --- PASO 1: Viabilidad del flujo inicial ---
    // Creamos una red para balancear las demandas y conservar el flujo
    int source_aux = 0;
    int sink_aux = n + 1;
    adj.assign(n + 2, vector<Edge>());
    level.resize(n + 2);
    ptr.resize(n + 2);

    for (int i = 1; i <= n; ++i) {
        if (i == s || i == t) continue;
        long long balance = in_degree[i] - out_degree[i];
        if (balance > 0) {
            add_edge(source_aux, i, balance);
        } else if (balance < 0) {
            add_edge(i, sink_aux, -balance);
        }
    }

    // Añadimos las aristas donde g_i = 1 con capacidad infinita para permitir el rebalanceo
    for (int i = 0; i < m; ++i) {
        if (input_edges[i].g == 1) {
            add_edge(input_edges[i].u, input_edges[i].v, INF, i);
        }
    }
    // Una arista de retorno infinita de t a s para cerrar el ciclo circulatorio
    add_edge(t, s, INF);

    dinic(source_aux, sink_aux);

    // Extraemos los flujos calculados que balancean el sistema
    vector<long long> f(m, 0);
    for (int i = 0; i < m; ++i) {
        if (input_edges[i].g == 1) f[i] = 1; 
    }

    for (int v = 0; v <= n + 1; ++v) {
        for (auto& edge : adj[v]) {
            if (edge.id != -1) {
                f[edge.id] += edge.flow;
            }
        }
    }

    // Multiplicamos por un factor de escala para poder manejar holguras cómodamente
    for (int i = 0; i < m; ++i) {
        f[i] *= 10;
    }

    // --- PASO 2: Corte Mínimo para encontrar las aristas a saturar ---
    adj.assign(n + 1, vector<Edge>());
    level.resize(n + 1);
    ptr.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        if (input_edges[i].g == 1) {
            // Cada arista con flujo cuesta 1 saturarla
            add_edge(input_edges[i].u, input_edges[i].v, 1, i);
        }
    }

    int k = dinic(s, t);

    visited_cut.assign(n + 1, false);
    dfs_cut(s);

    // Identificamos cuáles aristas cruzan el corte (de visitado a no visitado)
    vector<bool> is_saturated(m, false);
    for (int v = 1; v <= n; ++v) {
        if (!visited_cut[v]) continue;
        for (auto& edge : adj[v]) {
            if (edge.id != -1 && !visited_cut[edge.to]) {
                is_saturated[edge.id] = true;
            }
        }
    }

    // --- PASO 3: Imprimir Resultados ---
    cout << k << "\n";
    for (int i = 0; i < m; ++i) {
        if (input_edges[i].g == 0) {
            // Sin flujo, capacidad grande no saturada
            cout << "0 1000000000\n";
        } else {
            if (is_saturated[i]) {
                // Satisface f_i = c_i
                cout << f[i] << " " << f[i] << "\n";
            } else {
                // Satisface f_i < c_i
                cout << f[i] << " " << f[i] + 5 << "\n";
            }
        }
    }

    return 0;
}