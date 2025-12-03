// Tema 4: Buscar caminos mas cortos
// Algoritmo Bellman-ford

// Area de inclusiones
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Arista {
    int u;
    int v;
    int w;
};

int main() {
    int n, m;
    cout << "Numero de vertices: ";
    cin >> n;
    cout << "Numero de aristas: ";
    cin >> m;

    int dirigido, ponderado;
    cout << "Grafo dirigido? (1=si, 0=no): ";
    cin >> dirigido;
    cout << "Grafo ponderado? (1=si, 0=no): ";
    cin >> ponderado;

    vector<Arista> aristas;

    cout << "Ingresa las aristas (u v [w]):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w = 1;

        if (ponderado) cin >> u >> v >> w;
        else {
            cin >> u >> v;
            w = 1;
        }

        aristas.push_back((Arista){u, v, w});

        if (!dirigido)
            aristas.push_back((Arista){v, u, w});
    }

    const int INF = numeric_limits<int>::max();
    vector<int> dist(n, INF);
    dist[0] = 0;

    // Relajar V-1 veces
    for (int i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < aristas.size(); j++) {
            int a = aristas[j].u;
            int b = aristas[j].v;
            int w = aristas[j].w;

            if (dist[a] != INF && dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
            }
        }
    }

    // Detectar ciclo negativo
    for (size_t j = 0; j < aristas.size(); j++) {
        int a = aristas[j].u;
        int b = aristas[j].v;
        int w = aristas[j].w;

        if (dist[a] != INF && dist[a] + w < dist[b]) {
            cout << "\nExiste un ciclo negativo\n";
            return 0;
        }
    }

    // Mostrar distancias
    cout << "\nDistancias desde 0:\n";
    for (int i = 0; i < n; i++)
        cout << "Nodo " << i << ": " << dist[i] << endl;

    return 0;
}