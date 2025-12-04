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

void leerGrafoBipartito(GrafoBipartito &g) {
    int m;
    int esPonderado;
    cout << "Numero de vertices en la parte izquierda U: ";
    cin >> g.nIzq;
    cout << "Numero de vertices en la parte derecha V: ";
    cin >> g.nDer;
    cout << "Numero de aristas: ";
    cin >> m;
    cout << "Es ponderado? (1 = si, 0 = no): ";
    cin >> esPonderado;
    g.ponderado = (esPonderado != 0);
    g.aristas.clear();
    g.pesos.clear();

    cout << "Introduce las aristas (u v [peso]) con u en [0," << g.nIzq - 1
         << "] y v en [0," << g.nDer - 1 << "]:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w = 1;
        if (g.ponderado) {
            cin >> u >> v >> w;
            g.pesos.push_back(w);
        } else {
            cin >> u >> v;
        }
        g.aristas.push_back({u, v});
    }
    cout << "Nota: El grafo se considera no dirigido para efectos del pareo.\n";
}


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

void imprimirPareo(const vector<pair<int,int>> &pareo, bool esBipartito = true) {
    cout << "Pareo:\n";
    for (size_t i = 0; i < pareo.size(); ++i) {
        if (esBipartito)
            cout << "U " << pareo[i].first << " - V " << pareo[i].second << "\n";
        else
            cout << pareo[i].first << " - " << pareo[i].second << "\n";
    }
    cout << "Tamano del pareo: " << pareo.size() << "\n";
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
    GrafoBipartito g;
    bool cargado = false;
    int opcion;

    while (true) {
        cout << "\n===== MENU PAREOS EN GRAFO BIPARTITO =====\n";
        cout << "1) Capturar grafo bipartito\n";
        cout << "2) Calcular pareo maximal (greedy)\n";
        cout << "3) Calcular pareo maximo (Hopcroft-Karp) y verificar si es perfecto\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Terminando programa.\n";
            break;
        }

        if (opcion == 0) break;

        if (opcion == 1) {
            leerGrafoBipartito(g);
            cargado = true;
        } else if (opcion == 2) {
            if (!cargado) {
                cout << "Primero captura el grafo (opcion 1).\n";
                continue;
            }
            auto pareo = pareoMaximal(g);
            imprimirPareo(pareo, true);

        } else if (opcion == 3) {
            if (!cargado) {
                cout << "Primero captura el grafo (opcion 1).\n";
                continue;
            }
            vector<int> pareoU, pareoV;
            int tam = hopcroftKarp(g, pareoU, pareoV);
            cout << "Tamano del pareo maximo: " << tam << "\n";
            vector<pair<int,int>> lista;

            for (int u = 0; u < g.nIzq; ++u) {
                if (pareoU[u] != -1) {
                    lista.push_back({u, pareoU[u]});
                }
            }
            imprimirPareo(lista, true);

            bool perfecto = false;
            if (g.nIzq == g.nDer && tam == g.nIzq) perfecto = true;

            if (perfecto)
                cout << "El pareo maximo ES perfecto (cubre todos los vertices).\n";
            else
                cout << "El pareo maximo NO es perfecto.\n";

        } else {
            cout << "Opcion no valida.\n";
        }
    }

    return 0;
}
