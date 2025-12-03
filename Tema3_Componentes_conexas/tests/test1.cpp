#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    bool dirigido;
    vector<vector<int>> adj;

public:
    Graph(int V, bool dirigido) : V(V), dirigido(dirigido) {
        adj.resize(V);
    }

    void agregarArista(int u, int v) {
        adj[u].push_back(v);
        if (!dirigido) adj[v].push_back(u);
    }

    void dfs(int u, vector<bool>& visitado, vector<int>& comp) {
        visitado[u] = true;
        comp.push_back(u);
        for (int v : adj[u]) {
            if (!visitado[v]) dfs(v, visitado, comp);
        }
    }

    void bfs(int inicio, vector<bool>& visitado, vector<int>& comp) {
        queue<int> q;
        q.push(inicio);
        visitado[inicio] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            comp.push_back(u);
            for (int v : adj[u]) {
                if (!visitado[v]) {
                    visitado[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void componentesConexas(bool usarDFS) {
        vector<bool> visitado(V, false);
        int compId = 1;

        cout << "Componentes:\n";
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                vector<int> comp;

                if (usarDFS) dfs(i, visitado, comp);
                else bfs(i, visitado, comp);

                cout << "Componente " << compId++ << ": ";
                for (int x : comp) cout << x << " ";
                cout << "\n";
            }
        }
        cout << "\n";
    }
};


int main() {

    cout << "TEST 1: Grafo NO DIRIGIDO - NO PONDERADO\n";
    
    Graph g1(4, false);
    g1.agregarArista(0,1);
    g1.agregarArista(0,2);
    g1.agregarArista(1,3);
    g1.agregarArista(2,3);

    cout << "DFS:\n";
    g1.componentesConexas(true);
    cout << "BFS:\n";
    g1.componentesConexas(false);


    cout << "TEST 2: GRAFO DIRIGIDO - NO PONDERADO\n";

    Graph g2(4, true);
    g2.agregarArista(0,1);
    g2.agregarArista(1,2);
    g2.agregarArista(2,3);

    cout << "DFS:\n";
    g2.componentesConexas(true);
    cout << "BFS:\n";
    g2.componentesConexas(false);


    cout << "TEST 3: NO DIRIGIDO - PONDERADO (peso ignorado)\n";

    Graph g3(4, false);
    // 0-1 (2), 0-2 (5), 1-3 (3), 2-3 (1)
    g3.agregarArista(0,1);
    g3.agregarArista(0,2);
    g3.agregarArista(1,3);
    g3.agregarArista(2,3);

    cout << "DFS:\n";
    g3.componentesConexas(true);
    cout << "BFS:\n";
    g3.componentesConexas(false);



    cout << "TEST 4: DIRIGIDO - PONDERADO (peso ignorado)\n";

    Graph g4(4, true);
    // 0→1 (3), 1→2 (4), 2→3 (2), 3→0 (1)
    g4.agregarArista(0,1);
    g4.agregarArista(1,2);
    g4.agregarArista(2,3);
    g4.agregarArista(3,0);

    cout << "DFS:\n";
    g4.componentesConexas(true);
    cout << "BFS:\n";
    g4.componentesConexas(false);


    return 0;
}
