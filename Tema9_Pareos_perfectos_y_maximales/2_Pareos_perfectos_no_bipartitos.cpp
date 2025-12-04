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

int main(){}