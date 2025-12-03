#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Algoritmo Hungaro para costo minimo de asignacion en matriz cuadrada
// Devuelve el emparejamiento y el costo total minimo.

pair<vector<int>, int> hungaroMinimo(const vector<vector<int>> &costo) {
    int n = (int)costo.size();
    const int INF = numeric_limits<int>::max();
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<bool> usado(n + 1, false);
        do {
            usado[j0] = true;
            int i0 = p[j0], delta = INF, j1 = 0;
            for (int j = 1; j <= n; ++j) {
                if (!usado[j]) {
                    int cur = costo[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (usado[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    vector<int> asignacion(n, -1);
    for (int j = 1; j <= n; ++j) {
        if (p[j] != 0) {
            asignacion[p[j] - 1] = j - 1;
        }
    }

    int costoTotal = 0;
    for (int i = 0; i < n; ++i) {
        costoTotal += costo[i][asignacion[i]];
    }
    return {asignacion, costoTotal};
}


int main() {

    int opcion;
    while (true) {
        cout << "\n===== MENU PAREO MAXIMO (ALGORITMO HUNGARO) =====\n";
        cout << "Este programa asume un grafo bipartito completo, modelado como matriz de costos.\n";
        cout << "1) Resolver pareo de costo MINIMO\n";
        cout << "2) Resolver pareo de costo MAXIMO\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";
        if (!(cin >> opcion)) return 0;

        if (opcion == 0) break;

    }
    
        if (opcion == 1 || opcion == 2) {
            int n;
            cout << "Tamano de la matriz (n x n): ";
            cin >> n;
            cout << "Introduce la matriz de costos (" << n << " filas de " << n << " enteros):\n";

            vector<vector<int>> costo(n, vector<int>(n));
            int maxValor = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cin >> costo[i][j];
                    if (costo[i][j] > maxValor) maxValor = costo[i][j];
                }
            }

            if (opcion == 2) {
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        costo[i][j] = maxValor - costo[i][j];
            }

            auto res = hungaroMinimo(costo);
            vector<int> asign = res.first;
            int costoTransformado = res.second;

            int costoOriginal = 0;
            if (opcion == 1) {
                costoOriginal = costoTransformado;
            } else {
                costoOriginal = n * maxValor - costoTransformado;
            }

            cout << "Pareo encontrado (fila -> columna):\n";
            for (int i = 0; i < n; ++i) {
                cout << "Fila " << i << " -> Columna " << asign[i] << "\n";
            }
            if (opcion == 1)
                cout << "Costo total MINIMO: " << costoOriginal << "\n";
            else
                cout << "Costo total MAXIMO: " << costoOriginal << "\n";

        } else {
            cout << "Opcion no valida.\n";
        }
    return 0;
}