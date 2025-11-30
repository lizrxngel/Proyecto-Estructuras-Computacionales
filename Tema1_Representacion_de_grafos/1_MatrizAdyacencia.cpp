// Tema 1: Representación de grafos usando matriz de adyacencia

// Área de inclusiones
#include <iostream>
#include <vector>
using namespace std;

// Funcion princiapal
int main() {
    int n, tipoGrafo, tipoPeso;

    // Solicitar número de nodos
    cout << "Numero de nodos: ";
    cin >> n;

    // Crear matriz n x n inicializada en 0
    vector<vector<int>> matriz(n, vector<int>(n, 0));

    // Selección del tipo de grafo
    cout << "\nTipo de grafo:\n";
    cout << "1. No dirigido\n";
    cout << "2. Dirigido\n";
    cout << "Selecciona: ";
    cin >> tipoGrafo;

    // Selección del tipo de ponderación
    cout << "\nTipo de ponderacion:\n";
    cout << "1. No ponderado\n";
    cout << "2. Ponderado\n";
    cout << "Selecciona: ";
    cin >> tipoPeso;

    // Número de aristas
    int aristas;
    cout << "\nNumero de aristas: ";
    cin >> aristas;

    cout << "\nIngresa cada arista (u v peso(si es ponderado)):\n";
    cout << "(Nota: los nodos van de 0 a " << n-1 << ")\n";

    // Lectura de aristas
    for (int i = 0; i < aristas; i++) {
        int u, v, w = 1; // peso = 1 si no es ponderado

        if (tipoPeso == 2) cin >> u >> v >> w; // ponderado
        else cin >> u >> v;                    // no ponderado

        // Validación de rango de nodos
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Error: nodo fuera de rango. Arista ignorada.\n";
            continue;
        }

        // Asignación en la matriz según el tipo de grafo
        switch (tipoGrafo) {
            case 1: // No dirigido
                matriz[u][v] = w;
                matriz[v][u] = w; // duplicar valor en la otra dirección
                break;

            case 2: // Dirigido
                matriz[u][v] = w;
                break;

            default:
                cout << "Tipo de grafo invalido.\n";
                return 0;
        }
    }

    // Mostrar la matriz de adyacencia
    cout << "\nMatriz de adyacencia:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}