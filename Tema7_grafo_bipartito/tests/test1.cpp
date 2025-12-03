#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODES = 10;

// ====================== FUNCIONES DEL ALGORITMO ========================
vector< vector<int> > multiplicar_matrices(const vector< vector<int> >& A,
                                           const vector< vector<int> >& B,
                                           int V)
{
    vector< vector<int> > C(V, vector<int>(V, 0));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            for (int k = 0; k < V; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

bool verificar_bipartito_matriz(const vector< vector<int> >& matriz_adyacencia, int V)
{
    vector< vector<int> > potencia_actual = matriz_adyacencia;

    for (int k = 3; k <= V; k += 2) {

        potencia_actual = multiplicar_matrices(potencia_actual, matriz_adyacencia, V);
        potencia_actual = multiplicar_matrices(potencia_actual, matriz_adyacencia, V);

        cout << " -> Revisando ciclos impares de longitud: " << k << endl;

        for (int i = 0; i < V; ++i) {
            if (potencia_actual[i][i] > 0) {
                cout << "[CICLO IMPAR] Detectado ciclo de longitud " << k
                     << " en el nodo " << (i + 1) << endl;
                return false;
            }
        }
    }

    return true;
}

void mostrarMatriz(const vector< vector<int> >& M, int V)
{
    cout << "\nMATRIZ DE ADYACENCIA:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

// ============================== TEST ==================================
int main()
{
    cout << "==============================================\n";
    cout << "        TEST AUTOMATICO — MATRICES\n";
    cout << "==============================================\n";

    // -------------------------------------------------------------
    // GRAFO DE PRUEBA (modifica este para probar otros)
    // -------------------------------------------------------------
    int V = 5;
    vector< vector<int> > A(V, vector<int>(V, 0));

    // Grafo NO bipartito (contiene un ciclo impar)
    A[0][1] = A[1][0] = 1;
    A[1][2] = A[2][1] = 1;
    A[2][0] = A[0][2] = 1;  // ← forma un triángulo (ciclo de 3)

    // -------------------------------------------------------------
    mostrarMatriz(A, V);

    bool bip = verificar_bipartito_matriz(A, V);

    cout << "\n==============================================\n";
    cout << "                  RESULTADO\n";
    cout << "==============================================\n";

    if (bip) {
        cout << "El grafo ES bipartito.\n";
    } else {
        cout << "El grafo NO es bipartito.\n";
    }

    return 0;
}
