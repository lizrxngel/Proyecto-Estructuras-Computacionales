// Tema 2: Recorrido de grafos
// DFS

// Área de inclusiones
#include <iostream>
#include <vector>
using namespace std;

// Función recursiva para DFS
void dfs(int u, vector<vector<int>>& matriz, vector<bool>& visitado, int n) {
    visitado[u] = true;
    cout << u << " ";

    // Revisar vecinos de u
    for (int v = 0; v < n; v++) {
        if (matriz[u][v] != 0 && !visitado[v]) {
            dfs(v, matriz, visitado, n);
        }
    }
}

int main() {
    int n, tipoGrafo, tipoPeso;

    cout << "Numero de nodos: ";
    cin >> n;

    // Crear matriz n x n inicializada en 0
    vector<vector<int>> matriz(n, vector<int>(n, 0));

    cout << "\nTipo de grafo:\n";
    cout << "1. No dirigido\n";
    cout << "2. Dirigido\n";
    cout << "Selecciona: ";
    cin >> tipoGrafo;

    cout << "\nTipo de ponderacion:\n";
    cout << "1. No ponderado\n";
    cout << "2. Ponderado\n";
    cout << "Selecciona: ";
    cin >> tipoPeso;

    int aristas;
    cout << "\nNumero de aristas: ";
    cin >> aristas;

    cout << "\nIngresa cada arista (u v peso_si_aplica):\n";
    cout << "(Nota: los nodos van de 0 a " << n-1 << ")\n";

    for (int i = 0; i < aristas; i++) {
        int u, v, w = 1;
        if (tipoPeso == 2) cin >> u >> v >> w;
        else cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Error: nodo fuera de rango. Arista ignorada.\n";
            continue;
        }

        switch (tipoGrafo) {
            case 1: // No dirigido
                matriz[u][v] = w;
                matriz[v][u] = w;
                break;
            case 2: // Dirigido
                matriz[u][v] = w;
                break;
            default:
                cout << "Tipo de grafo invalido.\n";
                return 0;
        }
    }

    // DFS
    int inicio;
    cout << "\nNodo inicial para DFS: ";
    cin >> inicio;

    vector<bool> visitado(n, false);

    cout << "\nRecorrido DFS: ";
    dfs(inicio, matriz, visitado, n);

    cout << endl;
    return 0;
}