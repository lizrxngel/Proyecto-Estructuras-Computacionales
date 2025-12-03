#include <iostream>
#include <vector>
using namespace std;

struct Arista {
    int u, v;
    int peso;
};

struct Grafo {
    int n;
    bool dirigido;
    bool ponderado;
    vector<Arista> aristas;

    Grafo(int n = 0, bool dirigido = false, bool ponderado = false)
        : n(n), dirigido(dirigido), ponderado(ponderado) {}
};

vector<pair<int,int>> pareoMaximal(const Grafo &g) {
    vector<bool> usado(g.n, false);
    vector<pair<int,int>> pareo;

    for (size_t i = 0; i < g.aristas.size(); ++i) {
        int u = g.aristas[i].u;
        int v = g.aristas[i].v;
        if (u < 0 || u >= g.n || v < 0 || v >= g.n) continue;
        if (!usado[u] && !usado[v]) {
            usado[u] = usado[v] = true;
            pareo.push_back({u, v});
        }
    }
    return pareo;
}

int main() {
    // Grafo de prueba:
    // Vertices: 0,1,2,3
    // Aristas: 0-1, 1-2, 2-3
    Grafo g(4, false, false);
    g.aristas.push_back({0, 1, 1});
    g.aristas.push_back({1, 2, 1});
    g.aristas.push_back({2, 3, 1});

    auto pareo = pareoMaximal(g);

    cout << "Grafo de prueba (no dirigido, no ponderado):\n";
    cout << "Vertices: 0, 1, 2, 3\n";
    cout << "Aristas: (0,1), (1,2), (2,3)\n\n";

    cout << "Pareo maximal encontrado:\n";
    for (auto &p : pareo) {
        cout << p.first << " - " << p.second << "\n";
    }
    cout << "Tamano: " << pareo.size() << "\n";

    return 0;
}
