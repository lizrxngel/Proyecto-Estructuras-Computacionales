// Tema 5: Ver si un grafo es arbol o no 
// Usando BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool conectado(int n, const vector<vector<int> > &g) {
    vector<bool> vis(n, false);
    queue<int> q;

    vis[0] = true;
    q.push(0);
    int cont = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];

            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
                cont++;
            }
        }
    }
    return cont == n;
}

bool esArbol2(int n, int m, const vector<vector<int> > &g, bool dirigido) {
    if (dirigido) return false;     // un árbol no es dirigido
    if (m != n - 1) return false;   // propiedad básica del árbol
    return conectado(n, g);         // verificar que sea conectado
}

int main() {
    int n, m;
    cout << "Numero de nodos: ";
    cin >> n;

    cout << "Numero de aristas: ";
    cin >> m;

    int dirigido, ponderado;
    cout << "Dirigido? (1=si,0=no): ";
    cin >> dirigido;

    cout << "Ponderado? (1=si,0=no): ";
    cin >> ponderado;

    vector<vector<int> > g(n);

    cout << "Ingresa las aristas (u v [w]):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w = 1;
        if (ponderado) cin >> u >> v >> w;
        else cin >> u >> v;

        g[u].push_back(v);
        if (!dirigido) g[v].push_back(u);
    }

    int op;
    do {
        cout << "\n===== MENU (PROPIEDADES + BFS) =====\n";
        cout << "1. Mostrar si es dirigido\n";
        cout << "2. Mostrar si es ponderado\n";
        cout << "3. Ver si es arbol\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        if (op == 1)
            cout << (dirigido ? "El grafo es dirigido\n" : "El grafo NO es dirigido\n");

        if (op == 2)
            cout << (ponderado ? "El grafo es ponderado\n" : "El grafo NO es ponderado\n");

        if (op == 3) {
            if (esArbol2(n, m, g, dirigido))
                cout << "El grafo ES un arbol\n";
            else
                cout << "El grafo NO es un arbol\n";
        }

    } while (op != 4);

    return 0;
}