#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Arista {
    int u, v;
    int peso;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== PAREO MAXIMAL (ALGORITMO VORAZ) ===\n\n";

    int tipoDirigido, tipoPonderado;
    cout << "Tipo de grafo:\n";
    cout << "  0) No dirigido\n";
    cout << "  1) Dirigido\n";
    cout << "Opcion: ";
    cin >> tipoDirigido;

    cout << "Ponderacion:\n";
    cout << "  0) No ponderado\n";
    cout << "  1) Ponderado\n";
    cout << "Opcion: ";
    cin >> tipoPonderado;

    int n, m;
    cout << "Numero de vertices: ";
    cin >> n;
    cout << "Numero de aristas: ";
    cin >> m;

    vector<Arista> aristas;
    aristas.reserve(m);

    cout << "\nNOTA: Los vertices se numeran de 1 a " << n << ".\n";
    cout << "Ingresa las aristas en el formato:\n";
    if (tipoPonderado == 1) {
        cout << "u v peso\n";
    } else {
        cout << "u v\n";
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w = 1;
        if (tipoPonderado == 1) {
            cin >> u >> v >> w;
        } else {
            cin >> u >> v;
        }
        Arista a;
        a.u = u;
        a.v = v;
        a.peso = w;
        aristas.push_back(a);
    }
}