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

void leerGrafo(Grafo &g) {
    int n, m;
    int esDirigido, esPonderado;
    cout << "Numero de vertices: ";
    cin >> n;
    cout << "Numero de aristas: ";
    cin >> m;
    cout << "Es dirigido? (1 = si, 0 = no): ";
    cin >> esDirigido;
    cout << "Es ponderado? (1 = si, 0 = no): ";
    cin >> esPonderado;

    g = Grafo(n, esDirigido != 0, esPonderado != 0);
    g.aristas.clear();
    cout << "Introduce las aristas (u v [peso]) con vertices de 0 a " << n - 1 << ":\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w = 1;
        if (g.ponderado) {
            cin >> u >> v >> w;
        } else {
            cin >> u >> v;
        }
        g.aristas.push_back({u, v, w});
    }
    cout << "Nota: Para el pareo se ignora la direccion y se trata como grafo no dirigido.\n";
}

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
    Grafo g;
    bool cargado = false;
    int opcion;

    while (true) {
        cout << "\n===== MENU PAREOS EN GRAFO NO BIPARTITO =====\n";
        cout << "1) Capturar grafo\n";
        cout << "2) Calcular pareo maximal y verificar si es perfecto\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Terminando programa.\n";
            break;
        }

        if (opcion == 0) break;

        if (opcion == 1) {
            leerGrafo(g);
            cargado = true;

        } else if (opcion == 2) {
            if (!cargado) {
                cout << "Primero captura el grafo (opcion 1).\n";
                continue;
            }

            vector<bool> usado;
            auto pareo = pareoMaximal(g, usado);

            cout << "\n===== RESULTADO PAREO MAXIMAL =====\n";
            cout << "Pareo maximal encontrado (lista de aristas u - v):\n";
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
                cout << "El pareo maximal obtenido ES perfecto (cubre todos los vertices).\n";
                cout << "Como todos los vertices estan emparejados y el numero de vertices es par,\n";
                cout << "este mismo pareo maximal es un PAREO PERFECTO.\n";
            } else {
                cout << "El pareo maximal obtenido NO es perfecto.\n";
                cout << "Existen vertices sin emparejar o el numero de vertices es impar.\n";
            }
        } else {
            cout << "Opcion no valida.\n";
        }
    }

    return 0;
}
