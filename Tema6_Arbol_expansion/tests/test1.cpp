#include <iostream>
#include <algorithm>
using namespace std;

/************* ESTRUCTURAS Y VARIABLES GLOBALES *************/

struct Arista {
    int u;  // origen
    int v;  // destino
    int w;  // peso
};

Arista aristas[300];
Arista mst[300];

int padre[300];
int rangoUF[300];

int N = 0;   // número de vértices
int E = 0;   // número de aristas
bool grafoTienePesos = true;

/******************** UNION–FIND ****************************/

void hacerSet(int n) {
    for(int i = 0; i < n; i++) {
        padre[i] = i;
        rangoUF[i] = 0;
    }
}

int encontrarPadre(int x) {
    if(padre[x] == x) return x;
    padre[x] = encontrarPadre(padre[x]);
    return padre[x];
}

void unir(int a, int b) {
    a = encontrarPadre(a);
    b = encontrarPadre(b);
    if(a != b) {
        if(rangoUF[a] < rangoUF[b])
            padre[a] = b;
        else if(rangoUF[b] < rangoUF[a])
            padre[b] = a;
        else {
            padre[b] = a;
            rangoUF[a]++;
        }
    }
}

bool compararAristas(const Arista &A, const Arista &B) {
    return A.w < B.w;
}

/*********************** KRUSKAL ****************************/

void ejecutarKruskal() {
    if(!grafoTienePesos) {
        cout << "\nERROR: El grafo no tiene pesos válidos.\n";
        return;
    }

    sort(aristas, aristas + E, compararAristas);
    hacerSet(N);

    int contador = 0;
    int pesoTotal = 0;

    for(int i = 0; i < E; i++) {
        int u = aristas[i].u;
        int v = aristas[i].v;

        if(encontrarPadre(u) != encontrarPadre(v)) {
            mst[contador++] = aristas[i];
            pesoTotal += aristas[i].w;
            unir(u, v);
        }
    }

    cout << "\nARBOL DE EXPANSION MINIMA (MST) \n";
    for(int i = 0; i < contador; i++)
        cout << mst[i].u << " -- " << mst[i].v
             << "  (peso = " << mst[i].w << ")\n";

    cout << "\nPeso total del MST = " << pesoTotal << "\n";
}

/******************** CAPTURA DEL USUARIO *******************/

void capturarGrafo() {
    cout << "\nNumero de vertices: ";
    cin >> N;

    cout << "Numero de aristas: ";
    cin >> E;

    grafoTienePesos = true;

    cout << "\nIngrese cada arista (u v peso):\n";
    for(int i = 0; i < E; i++) {
        cout << "Arista " << i << ": ";
        cin >> aristas[i].u >> aristas[i].v >> aristas[i].w;

        if(aristas[i].w <= 0) {
            cout << "\nERROR: Todas las aristas deben tener peso POSITIVO.\n";
            grafoTienePesos = false;
        }
    }

    if(!grafoTienePesos)
        cout << "\nEl grafo no es valido para Kruskal.\n";
}

/******************** GRAFOS PREDEFINIDOS *******************/

void cargarGrafoPredefinido(int tipo) {

    /******** 1 — NO dirigido, NO ponderado ********/
    if(tipo == 1) {
        N = 5;
        E = 6;
        grafoTienePesos = true;

        int datos[6][3] = {
            {0,1,1},{1,2,1},{2,3,1},
            {3,4,1},{4,0,1},{1,4,1}
        };

        for(int i = 0; i < E; i++) {
            aristas[i].u = datos[i][0];
            aristas[i].v = datos[i][1];
            aristas[i].w = datos[i][2];
        }

        cout << "\nGrafo NO dirigido y NO ponderado cargado.\n";
    }

    /******** 2 — DIRIGIDO, NO ponderado ********/
    else if(tipo == 2) {
        N = 5;
        E = 6;
        grafoTienePesos = true;

        int datos[6][3] = {
            {0,1,1},{1,3,1},
            {3,4,1},{4,2,1},
            {2,1,1},{0,2,1}
        };

        for(int i = 0; i < E; i++) {
            aristas[i].u = datos[i][0];
            aristas[i].v = datos[i][1];
            aristas[i].w = datos[i][2];
        }

        cout << "\nGrafo dirigido y NO ponderado cargado.\n";
    }

    /******** 3 — NO dirigido, ponderado ********/
    else if(tipo == 3) {
        N = 5;
        E = 12;
        grafoTienePesos = true;

        int datos[12][3] = {
            {0,1,4},{0,4,6},{0,3,9},
            {1,0,4},{1,3,8},{1,2,7},
            {2,1,7},{2,3,5},
            {3,2,5},{3,1,8},{3,0,9},
            {4,0,6}
        };

        for(int i = 0; i < E; i++) {
            aristas[i].u = datos[i][0];
            aristas[i].v = datos[i][1];
            aristas[i].w = datos[i][2];
        }

        cout << "\nGrafo NO dirigido y ponderado cargado.\n";
    }

    /******** 4 — DIRIGIDO, ponderado ********/
    else if(tipo == 4) {
        N = 5;
        E = 6;
        grafoTienePesos = true;

        int datos[6][3] = {
            {1,0,3},{0,3,12},
            {1,2,18},{3,2,15},
            {3,1,9},{4,0,6}
        };

        for(int i = 0; i < E; i++) {
            aristas[i].u = datos[i][0];
            aristas[i].v = datos[i][1];
            aristas[i].w = datos[i][2];
        }

        cout << "\nGrafo dirigido y ponderado cargado.\n";
    }
}

/******************** MENÚ DE GRAFOS ************************/

void menuGrafos() {
    int opcion;

    cout << "\nSELECCION DE GRAFOS \n";
    cout << "1. Grafo NO dirigido y NO ponderado\n";
    cout << "2. Grafo dirigido y NO ponderado\n";
    cout << "3. Grafo NO dirigido y ponderado\n";
    cout << "4. Grafo dirigido y ponderado\n";
    cout << "5. Ingresar grafo manualmente\n";
    cout << "Opcion: ";
    cin >> opcion;

    if(opcion >= 1 && opcion <= 4)
        cargarGrafoPredefinido(opcion);
    else if(opcion == 5)
        capturarGrafo();
    else
        cout << "\nOpcion invalida.\n";
}

/************************ MAIN ******************************/

int main() {
    int op;

    do {
        cout << "\n MENU \n";
        cout << "1. Seleccionar grafo\n";
        cout << "2. Ejecutar Kruskal\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        if(op == 1)
            menuGrafos();
        else if(op == 2)
            ejecutarKruskal();

    } while(op != 0);

    return 0;
}
