#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Algoritmo Hungaro para costo MINIMO en matriz cuadrada
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
    // Matriz de costos de prueba (3x3)
    //  4 1 3
    //  2 0 5
    //  3 2 2
    vector<vector<int>> costoOriginal = {
        {4, 1, 3},
        {2, 0, 5},
        {3, 2, 2}
    };

    int n = (int)costoOriginal.size();

    cout << "Matriz de costos de prueba:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << costoOriginal[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int maxValor = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (costoOriginal[i][j] > maxValor)
                maxValor = costoOriginal[i][j];

    vector<vector<int>> costoTransformado(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            costoTransformado[i][j] = maxValor - costoOriginal[i][j];

    auto resMax = hungaroMinimo(costoTransformado);
    vector<int> asignMax = resMax.first;
    int costoTransformadoMin = resMax.second;

    int costoMaximo = n * maxValor - costoTransformadoMin;

    cout << "Pareo de COSTO MAXIMO (fila -> columna):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Fila " << i << " -> Columna " << asignMax[i] << "\n";
    }
    cout << "Costo total MAXIMO: " << costoMaximo << "\n";

    return 0;
}
