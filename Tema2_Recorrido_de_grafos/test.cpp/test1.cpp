#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Ejecuta BFS sobre una matriz dada
void BFS(const vector<vector<int>>& matriz, int inicio) {
    int n = matriz.size();
    vector<bool> visitado(n, false);
    queue<int> q;

    visitado[inicio] = true;
    q.push(inicio);

    cout << "BFS desde nodo " << inicio << ": ";

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (matriz[u][v] != 0 && !visitado[v]) {
                visitado[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n\n";
}

// Imprime matriz
void imprimirMatriz(const vector<vector<int>>& m) {
    for (auto& fila : m) {
        for (int x : fila) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    cout << " TEST 1: Grafo NO DIRIGIDO - NO PONDERADO\n";

    // Grafo:
    // 0 - 1
    // |   |
    // 2 - 3
    vector<vector<int>> g1 = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };
    imprimirMatriz(g1);
    BFS(g1, 0);

    cout << " TEST 2: Grafo DIRIGIDO - NO PONDERADO\n";

    // Grafo dirigido:
    // 0 → 1 → 2 → 3
    vector<vector<int>> g2 = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0}
    };
    imprimirMatriz(g2);
    BFS(g2, 0);

    cout << " TEST 3: Grafo NO DIRIGIDO - PONDERADO\n";

    // 0 -2- 1
    // |5   |3
    // 2 -1- 3
    vector<vector<int>> g3 = {
        {0,2,5,0},
        {2,0,0,3},
        {5,0,0,1},
        {0,3,1,0}
    };
    imprimirMatriz(g3);
    BFS(g3, 0);

    cout << " TEST 4: Grafo DIRIGIDO - PONDERADO\n";

    // 0 →3→ 1 →4→ 2
    // ↑         ↓2
    //  └---1---- 3
    vector<vector<int>> g4 = {
        {0,3,0,0},
        {0,0,4,0},
        {0,0,0,2},
        {1,0,0,0}
    };
    imprimirMatriz(g4);
    BFS(g4, 3);

    return 0;
}
