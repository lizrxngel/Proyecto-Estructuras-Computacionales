#include <iostream>
#include <vector>
using namespace std;

// DFS recursivo
void dfs(int u, const vector<vector<int>>& matriz, vector<bool>& visitado) {
    visitado[u] = true;
    cout << u << " ";
    int n = matriz.size();

    for (int v = 0; v < n; v++) {
        if (matriz[u][v] != 0 && !visitado[v]) {
            dfs(v, matriz, visitado);
        }
    }
}

// Función para imprimir la matriz de adyacencia
void imprimirMatriz(const vector<vector<int>>& m) {
    for (auto& fila : m) {
        for (int x : fila) cout << x << " ";
        cout << "\n";
    }
}

int main() {

    cout << " TEST 1: Grafo NO DIRIGIDO - NO PONDERADO\n";

    vector<vector<int>> g1 = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };
    imprimirMatriz(g1);
    cout << "DFS desde 0: ";
    dfs(0, g1, *(new vector<bool>(4, false)));
    cout << "\n\n";


    cout << " TEST 2: Grafo DIRIGIDO - NO PONDERADO\n";

    vector<vector<int>> g2 = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0}
    };
    imprimirMatriz(g2);
    cout << "DFS desde 0: ";
    dfs(0, g2, *(new vector<bool>(4, false)));
    cout << "\n\n";

    cout << " TEST 3: Grafo NO DIRIGIDO - PONDERADO\n";

    vector<vector<int>> g3 = {
        {0,2,5,0},
        {2,0,0,3},
        {5,0,0,1},
        {0,3,1,0}
    };
    imprimirMatriz(g3);
    cout << "DFS desde 0: ";
    dfs(0, g3, *(new vector<bool>(4, false)));
    cout << "\n\n";


    cout << " TEST 4: Grafo DIRIGIDO - PONDERADO\n";

    vector<vector<int>> g4 = {
        {0,3,0,0},
        {0,0,4,0},
        {0,0,0,2},
        {1,0,0,0}
    };
    imprimirMatriz(g4);
    cout << "DFS desde 3: ";
    dfs(3, g4, *(new vector<bool>(4, false)));
    cout << "\n\n";

    return 0;
}
