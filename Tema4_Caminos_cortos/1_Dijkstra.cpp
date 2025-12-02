// Tema 4: Buscar caminos mas cortos
// Algoritmo Dijkstra

// Area de inclusiones
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// struct para guardar el peso y conexion de la arista
struct Arista {
    int destino;
    int peso;
};

// Funcion principal
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

    vector<vector<Arista> > grafo(n);

    // w es el peso
    cout << "Ingresa las aristas (u v [w]):\n";

    for (int i = 0; i < m; i++) {
        int u, v, w = 1;

        // si es ponderado se ignora el peso
        if (ponderado) cin >> u >> v >> w;
        else {
            cin >> u >> v;  // ignoramos el peso
            w = 1;
        }

        // agregar aristas 
        grafo[u].push_back((Arista){v, w});
        if (!dirigido)
            grafo[v].push_back((Arista){u, w});
    }

    // Dijkstra desde nodo 0
    const int INF = numeric_limits<int>::max();
    vector<int> dist(n, INF);
    dist[0] = 0;

    
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int costo = pq.top().first;
        int nodo = pq.top().second;
        pq.pop();

        if (costo > dist[nodo]) continue;

        for (size_t i = 0; i < grafo[nodo].size(); i++) {
            int vec = grafo[nodo][i].destino;
            int peso = grafo[nodo][i].peso;

            if (dist[nodo] + peso < dist[vec]) {
                dist[vec] = dist[nodo] + peso;
                pq.push(make_pair(dist[vec], vec));
            }
        }
    }

    // Mostrar distancias
    cout << "\nDistancias desde 0:\n";
    for (int i = 0; i < n; i++)
        cout << "Nodo " << i << ": " << dist[i] << endl;

    return 0;
}