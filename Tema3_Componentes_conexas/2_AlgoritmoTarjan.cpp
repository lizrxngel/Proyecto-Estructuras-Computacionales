// Tema 3: componentes conexas
// Encontrar componentes conexas usando el algoritmo de Tarjan

// Area de inclusiones
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int V; // numero de vertices
    bool dirigido; // si el grafo es dirigido o no
    vector<vector<int>> adj; // lista de adyacencia

    // Variables del algoritmo
    vector<int> disc; // Tiempos de descubrimiento
    vector<int> low;  // Low-link values
    vector<int> inStack; // Indica si un nodo está en la pila
    stack<int> st;  // Pila para nodos activos
    int timeDFS; // Reloj global DFS

public:
    Graph(int V, bool dirigido) {
        this->V = V;
        this->dirigido = dirigido;
        adj.resize(V);
    }

    // Agregar arista (peso ignorado)
    void agregarArista(int u, int v) {
        adj[u].push_back(v);
        if (!dirigido) adj[v].push_back(u);  // para no dirigidos
    }

    // Tarjan DFS
    void tarjanDFS(int u, vector<vector<int>>& sccs) {
        disc[u] = low[u] = ++timeDFS;
        st.push(u);
        inStack[u] = true;
        
        // Explorar vecinos
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                tarjanDFS(v, sccs);
                low[u] = min(low[u], low[v]); // actualizar low-link si v no ha sido descubierto
            }
            else if (inStack[v]) {
                // actualizar low-link si v esta en la pila
                low[u] = min(low[u], disc[v]);
            }
        }

        // Si u es raíz de una SCC
        if (low[u] == disc[u]) {
            vector<int> scc;
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                scc.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(scc);
        }
    }

    // Ejecutar Tarjan
    vector<vector<int>> componentesFuertementeConexos() {
        disc.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, 0);
        timeDFS = 0;

        vector<vector<int>> sccs;

        // Ejecutar el algoritmo desde cada nodo no visitado
        for (int i = 0; i < V; i++)
            if (disc[i] == -1)
                tarjanDFS(i, sccs);

        return sccs;
    }
};

int main() {
    int V, E, esdirigido;
    cout << "Numero de vertices: ";
    cin >> V;

    cout << "Numero de aristas: ";
    cin >> E;

    cout << "El grafo es dirigido? (1 = sí, 0 = no): ";
    cin >> esdirigido;

    Graph g(V, esdirigido);

    cout << "Ingresa las aristas (u v peso_opcional):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v;
        g.agregarArista(u, v); // peso ignorado
    }

    auto sccs = g.componentesFuertementeConexos();

    cout << "\nComponentes Fuertemente Conexos (SCC):\n";
    int id = 1;
    for (auto& comp : sccs) {
        cout << "SCC " << id++ << ": ";
        for (int x : comp) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
