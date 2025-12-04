#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


// Grafo bipartito: parte izquierda U (0..nIzq-1), parte derecha V (0..nDer-1)
struct GrafoBipartito {
    int nIzq, nDer;
    bool ponderado;
    vector<pair<int,int>> aristas;      // (u,v) con u en U, v en V
    vector<int> pesos;                  // opcional

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


int main(){

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

}