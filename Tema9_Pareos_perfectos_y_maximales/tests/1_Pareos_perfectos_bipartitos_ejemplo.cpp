#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


struct GrafoBipartito {
    int nIzq, nDer;
    bool ponderado;
    vector<pair<int,int>> aristas;
    vector<int> pesos;

    GrafoBipartito(int nIzq = 0, int nDer = 0, bool ponderado = false)
        : nIzq(nIzq), nDer(nDer), ponderado(ponderado) {}
};

vector<pair<int,int>> pareoMaximal(const GrafoBipartito &g) {
    vector<bool> usadoU(g.nIzq, false), usadoV(g.nDer, false);
    vector<pair<int,int>> pareo;
    for (size_t i = 0; i < g.aristas.size(); ++i) {
        int u = g.aristas[i].first;
        int v = g.aristas[i].second;
        if (u < 0 || u >= g.nIzq || v < 0 || v >= g.nDer) continue;
        if (!usadoU[u] && !usadoV[v]) {
            usadoU[u] = true;
            usadoV[v] = true;
            pareo.push_back({u, v});
        }
    }
    return pareo;
}

const int INFH = numeric_limits<int>::max();

bool bfsHK(const vector<vector<int>> &adjU, vector<int> &dist,
           const vector<int> &pareoV, const vector<int> &pareoU) {
    int nU = (int)adjU.size();
    queue<int> q;
    for (int u = 0; u < nU; ++u) {
        if (pareoU[u] == -1) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INFH;
        }
    }
    int distNulo = INFH;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] < distNulo) {
            for (int v : adjU[u]) {
                int u2 = pareoV[v];
                if (u2 == -1) {
                    distNulo = dist[u] + 1;
                } else if (dist[u2] == INFH) {
                    dist[u2] = dist[u] + 1;
                    q.push(u2);
                }
            }
        }
    }
    return distNulo != INFH;
}

bool dfsHK(int u, const vector<vector<int>> &adjU, vector<int> &dist,
           vector<int> &pareoV, vector<int> &pareoU) {
    for (int v : adjU[u]) {
        int u2 = pareoV[v];
        if (u2 == -1 || (dist[u2] == dist[u] + 1 && dfsHK(u2, adjU, dist, pareoV, pareoU))) {
            pareoU[u] = v;
            pareoV[v] = u;
            return true;
        }
    }
    dist[u] = INFH;
    return false;
}

int hopcroftKarp(const GrafoBipartito &g, vector<int> &pareoU, vector<int> &pareoV) {
    vector<vector<int>> adjU(g.nIzq);
    for (auto &e : g.aristas) {
        int u = e.first, v = e.second;
        if (u < 0 || u >= g.nIzq || v < 0 || v >= g.nDer) continue;
        adjU[u].push_back(v);
    }

    pareoU.assign(g.nIzq, -1);
    pareoV.assign(g.nDer, -1);
    vector<int> dist(g.nIzq);
    int matching = 0;

    while (bfsHK(adjU, dist, pareoV, pareoU)) {
        for (int u = 0; u < g.nIzq; ++u) {
            if (pareoU[u] == -1) {
                if (dfsHK(u, adjU, dist, pareoV, pareoU)) {
                    matching++;
                }
            }
        }
    }
    return matching;
}


int main() {

    GrafoBipartito g(3, 3, false);
    g.aristas.push_back({0,0});
    g.aristas.push_back({0,1});
    g.aristas.push_back({1,1});
    g.aristas.push_back({1,2});
    g.aristas.push_back({2,0});
    g.aristas.push_back({2,2});

    cout << "GRAFO BIPARTITO DE PRUEBA (Tema 9)\n";
    cout << "U = {0,1,2}, V = {0,1,2}\n";
    cout << "Aristas: (0,0), (0,1), (1,1), (1,2), (2,0), (2,2)\n\n";

    // Pareo maximal (greedy)
    auto pareoMax = pareoMaximal(g);
    cout << "Pareo maximal (greedy):\n";
    for (auto &p : pareoMax) {
        cout << "U " << p.first << " - V " << p.second << "\n";
    }
    cout << "Tamano del pareo maximal: " << pareoMax.size() << "\n\n";

    // Pareo maximo (Hopcroft-Karp)
    vector<int> pareoU, pareoV;
    int tam = hopcroftKarp(g, pareoU, pareoV);

    cout << "Pareo maximo (Hopcroft-Karp):\n";
    for (int u = 0; u < g.nIzq; ++u) {
        if (pareoU[u] != -1) {
            cout << "U " << u << " - V " << pareoU[u] << "\n";
        }
    }
    cout << "Tamano del pareo maximo: " << tam << "\n";

    bool perfecto = (g.nIzq == g.nDer && tam == g.nIzq);
    if (perfecto) {
        cout << "Este pareo maximo ES perfecto (cubre todos los vertices de U y V).\n";
    } else {
        cout << "Este pareo maximo NO es perfecto.\n";
    }

    return 0;
}
