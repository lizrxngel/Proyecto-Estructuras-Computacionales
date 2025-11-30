// Tema 2: Recorrido de grafos
// BFS

// Área de inclusiones
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Función principal
int main() {
    // Numero de nodos, dirigido/no dirigido, ponderado/no ponderado
    int n, tipoGrafo, tipoPeso;

    cout << "Numero de nodos: ";
    cin >> n;

    // Crear matriz n x n inicializada en 0
    vector<vector<int>> matriz(n, vector<int>(n, 0));

    // Ingresar el tipo de grafo que es
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

    // Ingresar el numero de aristas
    int aristas;
    cout << "\nNumero de aristas: ";
    cin >> aristas;

    // Ingresar conexiones
    cout << "\nIngresa cada arista (u v peso(si es ponderado)):\n";
    cout << "(Nota: los nodos van de 0 a " << n-1 << ")\n";

    for (int i = 0; i < aristas; i++) {
        int u, v, w = 1;
        if (tipoPeso == 2) cin >> u >> v >> w;
        else cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Error: nodo fuera de rango. Arista no registrada\n";
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

    // BFS
    int inicio;
    cout << "\nNodo inicial para BFS: ";
    cin >> inicio;

    vector<bool> visitado(n, false);
    queue<int> q;

    // Inicializar BFS
    visitado[inicio] = true;
    q.push(inicio);

    // BFS
    cout << "\nRecorrido BFS: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Revisar vecinos de u
        for (int v = 0; v < n; v++) {
            if (matriz[u][v] != 0 && !visitado[v]) {
                visitado[v] = true;
                q.push(v);
            }
        }
    }

    cout << endl;
    return 0;
}