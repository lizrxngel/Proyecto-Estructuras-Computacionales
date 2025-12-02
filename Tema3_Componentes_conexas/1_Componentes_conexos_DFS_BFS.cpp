// Tema 3: componentes conexas
// Encontrar componentes conexas usando BFS y DFS

// Area de inclusiones
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Grafo 
class Graph {
private:
    int V; // Numero de vertices
    bool dirigido; // indica si es dirigido o no
    vector<vector<int>> adj; // lista de adyacencia

public:
    Graph(int V, bool dirigido) {
        this->V = V;
        this->dirigido = dirigido;
        adj.resize(V);
    }

    // Agregar arista (ignora el peso)
    void agregarArista(int u, int v) {
        adj[u].push_back(v); // agrega vecinos de u
        // si el grafo no es dirigido se agrega que se
        // recorre de ambos lados
        if (!dirigido) adj[v].push_back(u);
    }

    // DFS Recursiva
    void dfs(int u, vector<bool>& visitado, vector<int>& comp) {
        visitado[u] = true; //Marcar visitado
        comp.push_back(u); // agregarlo al componente actual

        // recorrer los vecinos del nodo
        for (int v : adj[u]) { // si un vecino no esta visitado se activa la recursion
            if (!visitado[v]) dfs(v, visitado, comp);
        }
    }

    // BFS Iterativa
    void bfs(int inicio, vector<bool>& visitado, vector<int>& comp) {
        queue<int> q; // cola para bfs
        q.push(inicio);
        visitado[inicio] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            comp.push_back(u);

            // recorre vecinos y si no esta visitado se agrega vecino
            for (int v : adj[u]) {
                if (!visitado[v]) {
                    visitado[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // Componentes conexas (no dirigido) o débiles (dirigido)
    void componentesConexas(bool usarDFS = true) {
        vector<bool> visitado(V, false);
        int compId = 1;

        cout << "\nComponentes encontradas:\n";
        
        //Recorrer los nodos del grafo
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                vector<int> comp;
                
                // Usar BFS o DFS dependiendo de la opcion del usuario
                if (usarDFS) dfs(i, visitado, comp);
                else bfs(i, visitado, comp);
                
                // Imprimir componentes conexas
                cout << "Componente " << compId++ << ": ";
                for (int x : comp) cout << x << " ";
                cout << "\n";
            }
        }
    }
};

// Funcion principal
int main() {
    int V, E, esdirigido;
    cout << "Numero de vertices: ";
    cin >> V;

    cout << "Numero de aristas: ";
    cin >> E;

    cout << "El grafo es dirigido?: \n";
    cout << "1. Si\n";
    cout << "2. No\n";
    cin >> esdirigido;

    Graph g(V, esdirigido); // crea el objeto grafo

    cout << "Ingresa las aristas (u v peso(si es ponderado)):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v;
        g.agregarArista(u, v);  // ignoramos el peso
    }

    int metodo;
    cout << "\nMetodo para encontrar componentes:\n";
    cout << "1. DFS\n";
    cout << "2. BFS\n";
    cin >> metodo;

    if (metodo == 1)
        g.componentesConexas(true);
    else
        g.componentesConexas(false);

    return 0;
}
