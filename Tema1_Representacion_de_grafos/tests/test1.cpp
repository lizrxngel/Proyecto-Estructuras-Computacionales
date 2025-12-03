
// Tema 1: Representación de grafos usando matriz de adyacencia

#include <iostream>
#include <vector>
using namespace std;

// Función para imprimir matriz
void imprimirMatriz(const vector<vector<int>>& M) {
    for (auto& fila : M) {
        for (int val : fila) cout << val << " ";
        cout << endl;
    }
}

int main() {
    cout << "TEST 1: Grafo NO DIRIGIDO - NO PONDERADO\n";

    int n1 = 4; // nodos 0,1,2,3
    vector<vector<int>> grafo1(n1, vector<int>(n1, 0));

    // Aristas del grafo:
    // 0-1, 0-2, 1-3
    vector<pair<int,int>> aristas1 = {
        {0,1}, {0,2}, {1,3}
    };

    for (auto [u,v] : aristas1) {
        grafo1[u][v] = 1;
        grafo1[v][u] = 1; // no dirigido
    }

    imprimirMatriz(grafo1);

    cout << "\nTEST 2: Grafo DIRIGIDO - PONDERADO \n";

    int n2 = 5;
    vector<vector<int>> grafo2(n2, vector<int>(n2, 0));

    // Aristas dirigidas:
    // 0 → 1 (peso 3)
    // 1 → 3 (peso 5)
    // 2 → 1 (peso 2)
    // 3 → 4 (peso 7)
    vector<tuple<int,int,int>> aristas2 = {
        {0,1,3}, {1,3,5}, {2,1,2}, {3,4,7}
    };

    for (auto [u,v,w] : aristas2) {
        grafo2[u][v] = w; // dirigido
    }

    imprimirMatriz(grafo2);

    return 0;
}
