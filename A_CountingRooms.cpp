#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
char mapa[MAX][MAX];
bool visitado[MAX][MAX];
int n, m;

// Movimientos: arriba, abajo, izquierda, derecha
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visitado[x][y] = true;

    while (!q.empty()) {
        pair<int, int> actual = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = actual.first + dx[i];
            int ny = actual.second + dy[i];

            // Verificación rápida de límites y condiciones
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                mapa[nx][ny] == '.' && !visitado[nx][ny]) {
                
                visitado[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // Optimización extrema de entrada y salida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }

    int habitaciones = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Si es suelo y no lo hemos visitado, procesamos la habitación
            if (mapa[i][j] == '.' && !visitado[i][j]) {
                habitaciones++;
                bfs(i, j);
            }
        }
    }

    cout << habitaciones << "\n";

    return 0;
}