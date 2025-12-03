// Tema 1: Representación de grafos usando lista de adyacencia

#include <iostream>
#include <vector>
using namespace std;

void imprimirLista(const vector<vector<int>>& matriz) {
    cout << "\nLista de adyacencia:\n";
    int n = matriz.size();
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != 0) {
                cout << j << "(" << matriz[i][j] << ") ";
            }
        }
        cout << endl;
    }
}

int main() {

    cout << "TEST 1: Grafo NO DIRIGIDO - NO PONDERADO\n";

    int n1 = 4; // nodos: 0,1,2,3
    vector<vector<int>> grafo1(n1, vector<int>(n1, 0));

    // Aristas:
    // 0-1, 0-2, 1-3
    vector<pair<int,int>> aristas1 = {
        {0,1}, {0,2}, {1,3}
    };

    for (auto [u,v] : aristas1) {
        grafo1[u][v] = 1;
        grafo1[v][u] = 1; // porque NO dirigido
    }

    imprimirLista(grafo1);

    cout << "\nTEST 2: Grafo DIRIGIDO - PONDERADO \n";

    int n2 = 5;
    vector<vector<int>> grafo2(n2, vector<int>(n2, 0));

    // Aristas dirigidas:
    // 0 → 1 (3)
    // 1 → 3 (5)
    // 2 → 1 (2)
    // 3 → 4 (7)
    vector<tuple<int,int,int>> aristas2 = {
        {0,1,3}, {1,3,5}, {2,1,2}, {3,4,7}
    };

    for (auto [u,v,w] : aristas2) {
        grafo2[u][v] = w;
    }

    imprimirLista(grafo2);

    return 0;
}
