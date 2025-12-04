# Tema 8: Pareos máximos y maximales en grafos generales

## Algoritmo 1: Pareo maximal en grafo general (dirigido / no dirigido, ponderado / no ponderado)

Este programa calcula un **pareo maximal** en un grafo general.  
El grafo puede ser dirigido o no dirigido, y ponderado o no ponderado, pero para el pareo se interpreta como **no dirigido y sin pesos**. El algoritmo recorre la lista de aristas de forma greedy y va tomando aristas siempre que ambos vértices estén libres.

### Cómo usarlo

1. Al correr el programa verás un menú donde puedes escoger:
   - **Capturar grafo**
   - **Calcular pareo maximal**
   - **Salir**
2. Si escoges **Capturar grafo** debes:
   - Ingresar número de vértices.
   - Ingresar número de aristas.
   - Indicar si es dirigido (1/0).
   - Indicar si es ponderado (1/0).
   - Ingresar las aristas:
     - Si no es ponderado: `u v`
     - Si es ponderado: `u v peso`
3. Después, con la opción **Calcular pareo maximal**, el programa imprime:
   - Las aristas que forman el pareo.
   - El tamaño del pareo.

---

## Algoritmo 2: Pareo máximo con algoritmo Húngaro (modelo como grafo bipartito)

Este programa resuelve el problema de **asignación** usando el **algoritmo Húngaro**, que encuentra un **pareo de costo mínimo** (o máximo, mediante transformación) en un grafo bipartito completo modelado como una matriz de costos `n x n`.  
Cada fila representa un vértice del lado izquierdo y cada columna uno del lado derecho.

### Cómo usarlo

1. Al correr el programa verás un menú donde puedes escoger:
   - **Resolver pareo de costo mínimo**
   - **Resolver pareo de costo máximo**
   - **Salir**
2. Si escoges una de las opciones de pareo debes:
   - Ingresar `n`, el tamaño de la matriz (`n x n`).
   - Ingresar la matriz de costos, fila por fila (valores enteros).
3. El programa imprime:
   - La asignación fila → columna (pareo en el grafo bipartito).
   - El costo total mínimo o máximo, según la opción elegida.

---

## Como compilar y ejecutar (Tema 8)

Estando en la raíz del proyecto y usando `g++`:

**Algoritmo 1 – Pareo maximal (grafo general)**

```bash
g++ Tema8_Pareo_en_un_grafo/1_PareoGrafo_maximal.cpp -o pareo_maximal
./pareo_maximal
