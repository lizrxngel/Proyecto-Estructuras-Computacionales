#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Algoritmo Hungaro para costo minimo de asignacion en matriz cuadrada
// Devuelve el emparejamiento y el costo total minimo.

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

    return 0;
}