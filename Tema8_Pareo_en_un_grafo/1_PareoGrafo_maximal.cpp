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
    if (!(cin >> n)) {
        cout << "Error leyendo numero de vertices.\n";
        return;
    }

    cout << "Numero de aristas: ";
    if (!(cin >> m)) {
        cout << "Error leyendo numero de aristas.\n";
        return;
    }

    cout << "Es dirigido? (1 = si, 0 = no): ";
    if (!(cin >> esDirigido)) {
        cout << "Error leyendo si es dirigido.\n";
        return;
    }

    cout << "Es ponderado? (1 = si, 0 = no): ";
    if (!(cin >> esPonderado)) {
        cout << "Error leyendo si es ponderado.\n";
        return;
    }

    g = Grafo(n, esDirigido != 0, esPonderado != 0);
    g.aristas.clear();

    cout << "Introduce las aristas (u v [peso]) con vertices de 0 a " << n - 1 << ":\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w = 1;
        if (g.ponderado) {
            if (!(cin >> u >> v >> w)) {
                cout << "Error leyendo arista.\n";
                return;
            }
        } else {
            if (!(cin >> u >> v)) {
                cout << "Error leyendo arista.\n";
                return;
            }
        }
        g.aristas.push_back({u, v, w});
    }
    cout << "Nota: Para el pareo se interpreta el grafo como NO dirigido.\n";
}

// Algoritmo greedy para obtener un pareo maximal
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

void imprimirPareo(const vector<pair<int,int>> &pareo) {
    cout << "Pareo encontrado:\n";
    for (size_t i = 0; i < pareo.size(); ++i) {
        cout << pareo[i].first << " - " << pareo[i].second << "\n";
    }
    cout << "Tamano del pareo: " << pareo.size() << "\n";
}

int main() {

    Grafo g;
    bool grafoCargado = false;
    int opcion;

    while (true) {
        cout << "\n===== MENU PAREO MAXIMAL (GRAFO GENERAL) =====\n";
        cout << "1) Capturar grafo\n";
        cout << "2) Calcular pareo maximal\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Terminando programa.\n";
            break;
        }

        if (opcion == 0) {
            cout << "Saliendo del programa...\n";
            break;
        } else if (opcion == 1) {
            leerGrafo(g);
            grafoCargado = true;
        } else if (opcion == 2) {
            if (!grafoCargado) {
                cout << "Primero debes capturar un grafo (opcion 1).\n";
                continue;
            }
            vector<pair<int,int>> pareo = pareoMaximal(g);
            imprimirPareo(pareo);
        } else {
            cout << "Opcion no valida.\n";
        }
    }

    return 0;
}
