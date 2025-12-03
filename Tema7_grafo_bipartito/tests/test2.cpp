#include <iostream>
#include <vector>
using namespace std;

// =======================================================
// DFS PARA VERIFICAR SI UN GRAFO ES BIPARTITO
// =======================================================
bool DFS_Bipartito(int u, int color_actual,
                   vector<vector<int>>& grafo,
                   vector<int>& color)
{
    color[u] = color_actual;

    for (int vecino : grafo[u]) {

        if (color[vecino] == -1) {
            if (!DFS_Bipartito(vecino, 1 - color_actual, grafo, color))
                return false;
        }
        else if (color[vecino] == color_actual) {
            cout << "\n[CONFLICTO] El nodo " << u
                 << " y el nodo " << vecino
                 << " tienen el mismo color.\n";
            return false;
        }
    }
    return true;
}

// =======================================================
// Mostrar matriz de adyacencia
// =======================================================
void mostrarMatriz(vector<vector<int>>& M, int V)
{
    cout << "\nMATRIZ DE ADYACENCIA:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

// =======================================================
// TEST AUTOMÁTICO
// =======================================================
int main()
{
    cout << "===============================================\n";
    cout << "   TEST AUTOMATICO — BIPARTITO (DFS)\n";
    cout << "===============================================\n";

    // ---------------------------------------------------------
    // GRAFO AUTOMATICO PARA LA PRUEBA
    //
    // Este grafo tiene un ciclo impar: 0–1–2–0
    // Por lo tanto NO es bipartito.
    // ---------------------------------------------------------
    int V = 5;
    vector<vector<int>> grafo(V);
    vector<vector<int>> matriz(V, vector<int>(V, 0));

    auto addEdge = [&](int u, int v) {
        grafo[u].push_back(v);
        grafo[v].push_back(u);
        matriz[u][v] = matriz[v][u] = 1;
    };

    // Triángulo (ciclo impar)
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);

    // Un par de conexiones extra
    addEdge(3, 4);

    // Mostrar matriz
    mostrarMatriz(matriz, V);

    // ---------------------------------------------------------
    // EJECUTAR DFS BIPARTITO
    // ---------------------------------------------------------
    vector<int> color(V, -1);
    bool es_bipartito = true;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!DFS_Bipartito(i, 0, grafo, color)) {
                es_bipartito = false;
                break;
            }
        }
    }

    // ---------------------------------------------------------
    // RESULTADO
    // ---------------------------------------------------------
    cout << "\n===============================================\n";
    cout << "                  RESULTADO\n";
    cout << "===============================================\n";

    if (es_bipartito) {
        cout << "[EXITO] El grafo ES bipartito.\n";
    } else {
        cout << "[FALLO] El grafo NO es bipartito.\n";
    }

    return 0;
}
