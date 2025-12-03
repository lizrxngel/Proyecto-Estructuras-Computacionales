#include <iostream>
using namespace std;

// ===============================================================
//  ARREGLOS PARA REPRESENTAR EL GRAFO
// ===============================================================
int adyNodo[100][100];
int adyPeso[100][100];
int grado[100];

int N, E;

// ===============================================================
//  ARREGLOS USADOS POR EL ALGORITMO DE PRIM
// ===============================================================
int dist_[100];
bool visitado[100];
int padre[100];

// ===============================================================
//  LIMPIAR TODO EL GRAFO
// ===============================================================
void limpiarGrafo()
{
    for(int i = 0; i < 100; i++)
    {
        grado[i] = 0;
        for(int j = 0; j < 100; j++)
        {
            adyNodo[i][j] = 0;
            adyPeso[i][j] = 0;
        }
    }
}

// ===============================================================
//  ALGORITMO DE PRIM
// ===============================================================
void ejecutarPrim()
{
    for(int i = 0; i < N; i++)
    {
        dist_[i] = 999999;
        visitado[i] = false;
        padre[i] = -1;
    }

    dist_[0] = 0;

    for(int iter = 0; iter < N; iter++)
    {
        int u = -1;
        int mejor = 999999;

        for(int i = 0; i < N; i++)
        {
            if(!visitado[i] && dist_[i] < mejor)
            {
                mejor = dist_[i];
                u = i;
            }
        }

        visitado[u] = true;

        for(int k = 0; k < grado[u]; k++)
        {
            int v = adyNodo[u][k];
            int w = adyPeso[u][k];

            if(!visitado[v] && w < dist_[v])
            {
                dist_[v] = w;
                padre[v] = u;
            }
        }
    }

    cout << "\n=========== MST OBTENIDO (Prim) ===========\n";
    
    int total = 0;
    for(int i = 1; i < N; i++)
    {
        cout << padre[i] << " -- " << i
             << "   (peso = " << dist_[i] << ")\n";
        total += dist_[i];
    }

    cout << "\nPeso total del MST = " << total << "\n";
}


// ===============================================================
//   TEST 1: GRAFO NO DIRIGIDO PONDERADO
// ===============================================================
void testNoDirigidoPonderado()
{
    limpiarGrafo();

    N = 5;
    int A[6][3] = {
        {0,1,4},
        {0,4,6},
        {1,2,7},
        {2,3,5},
        {1,3,12},
        {3,4,8}
    };
    E = 6;

    for(int i = 0; i < E; i++)
    {
        int u = A[i][0], v = A[i][1], w = A[i][2];

        adyNodo[u][grado[u]] = v;
        adyPeso[u][grado[u]] = w;
        grado[u]++;

        adyNodo[v][grado[v]] = u;
        adyPeso[v][grado[v]] = w;
        grado[v]++;
    }

    cout << "\n>>> TEST 1: Grafo NO dirigido PONDERADO\n";
    ejecutarPrim();
}

// ===============================================================
//   TEST 2: GRAFO NO DIRIGIDO NO PONDERADO (peso = 1)
// ===============================================================
void testNoDirigidoNoPonderado()
{
    limpiarGrafo();

    N = 5;
    int A[6][2] = {
        {0,1},
        {0,4},
        {1,2},
        {2,3},
        {1,3},
        {3,4}
    };
    E = 6;

    for(int i = 0; i < E; i++)
    {
        int u = A[i][0], v = A[i][1];

        adyNodo[u][grado[u]] = v;
        adyPeso[u][grado[u]] = 1;
        grado[u]++;

        adyNodo[v][grado[v]] = u;
        adyPeso[v][grado[v]] = 1;
        grado[v]++;
    }

    cout << "\n>>> TEST 2: Grafo NO dirigido NO ponderado (peso = 1)\n";
    ejecutarPrim();
}

// ===============================================================
//   TEST 3: GRAFO DIRIGIDO PONDERADO
// ===============================================================
void testDirigidoPonderado()
{
    limpiarGrafo();

    N = 5;
    int A[6][3] = {
        {0,1,4},
        {0,4,6},
        {1,2,7},
        {2,3,5},
        {1,3,12},
        {3,4,8}
    };
    E = 6;

    for(int i = 0; i < E; i++)
    {
        int u = A[i][0], v = A[i][1], w = A[i][2];

        adyNodo[u][grado[u]] = v;
        adyPeso[u][grado[u]] = w;
        grado[u]++;
    }

    cout << "\n>>> TEST 3: Grafo DIRIGIDO PONDERADO\n";
    ejecutarPrim();
}

// ===============================================================
//   TEST 4: GRAFO DIRIGIDO NO PONDERADO (peso = 1)
// ===============================================================
void testDirigidoNoPonderado()
{
    limpiarGrafo();

    N = 5;
    int A[6][2] = {
        {0,1},
        {0,4},
        {1,2},
        {2,3},
        {1,3},
        {3,4}
    };
    E = 6;

    for(int i = 0; i < E; i++)
    {
        int u = A[i][0], v = A[i][1];

        adyNodo[u][grado[u]] = v;
        adyPeso[u][grado[u]] = 1;
        grado[u]++;
    }

    cout << "\n>>> TEST 4: Grafo DIRIGIDO NO ponderado (peso = 1)\n";
    ejecutarPrim();
}


// ===============================================================
//  MAIN CON MENU DE TESTS
// ===============================================================
int main()
{
    int op;
    do {
        cout << "\n========== TESTS DE PRIM ==========\n";
        cout << "1. Test NO dirigido ponderado\n";
        cout << "2. Test NO dirigido NO ponderado\n";
        cout << "3. Test DIRIGIDO ponderado\n";
        cout << "4. Test DIRIGIDO NO ponderado\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        if(op == 1) testNoDirigidoPonderado();
        else if(op == 2) testNoDirigidoNoPonderado();
        else if(op == 3) testDirigidoPonderado();
        else if(op == 4) testDirigidoNoPonderado();

    } while(op != 0);

    return 0;
}
