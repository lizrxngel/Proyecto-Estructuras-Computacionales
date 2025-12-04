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

vector<pair<int,int>> pareoMaximal(const Grafo &g, vector<bool> &usado) {
    usado.assign(g.n, false);
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

    Grafo g(4, false, false);
    g.aristas.push_back({0,1,1});
    g.aristas.push_back({1,2,1});
    g.aristas.push_back({2,3,1});
    g.aristas.push_back({3,0,1});

    cout << "GRAFO NO BIPARTITO DE PRUEBA (Tema 9)\n";
    cout << "Vertices: 0, 1, 2, 3\n";
    cout << "Aristas: (0,1), (1,2), (2,3), (3,0)\n\n";

    vector<bool> usado;
    auto pareo = pareoMaximal(g, usado);

    cout << "Pareo maximal encontrado:\n";
    for (auto &p : pareo) {
        cout << p.first << " - " << p.second << "\n";
    }
    cout << "Tamano del pareo maximal: " << pareo.size() << "\n\n";

    bool perfecto = true;
    for (int i = 0; i < g.n; ++i) {
        if (!usado[i]) {
            perfecto = false;
            break;
        }
    }

    if (perfecto && g.n % 2 == 0 && (int)pareo.size() * 2 == g.n) {
        cout << "El pareo maximal ES perfecto (cubre todos los vertices).\n";
    } else {
        cout << "El pareo maximal NO es perfecto.\n";
    }

    cout << "\nIMPORTANTE: Este algoritmo es greedy y solo garantiza un pareo maximal,\n";
    cout << "no necesariamente el pareo maximo ni encontrar uno perfecto aunque exista.\n";

    return 0;
}
