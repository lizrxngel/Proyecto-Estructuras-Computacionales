# Proyecto-Estructuras-Computacionales
Proyecto final  de Estructuras Computacionales Avanzadas
# Tema 9: Pareos perfectos y maximales

## Algoritmo 1: Pareos perfectos y maximales en grafos bipartitos

Este programa trabaja con grafos bipartitos `G = (U, V, E)` y permite obtener:
- Un **pareo maximal** mediante un algoritmo greedy.
- Un **pareo máximo** mediante el algoritmo de **Hopcroft–Karp**, y verificar si ese pareo máximo es **perfecto** (cubre todos los vértices de ambos lados cuando |U| = |V|).

### Cómo usarlo

1. Al correr el programa verás un menú donde puedes escoger:
   - **Capturar grafo bipartito**
   - **Calcular pareo maximal (greedy)**
   - **Calcular pareo máximo (Hopcroft–Karp) y verificar si es perfecto**
   - **Salir**
2. Si escoges **Capturar grafo bipartito** debes:
   - Ingresar número de vértices en `U`.
   - Ingresar número de vértices en `V`.
   - Ingresar número de aristas.
   - Indicar si es ponderado (1/0).
   - Ingresar las aristas:
     - Si no es ponderado: `u v`
     - Si es ponderado: `u v peso` (el peso se ignora para el pareo, solo se almacena).
3. Con la opción **pareo maximal (greedy)** el programa:
   - Recorre las aristas en orden.
   - Toma una arista solo si ambos vértices están libres.
   - Imprime el pareo y su tamaño.
4. Con la opción **pareo máximo (Hopcroft–Karp)** el programa:
   - Calcula un pareo de **tamaño máximo**.
   - Imprime las parejas U–V del pareo.
   - Indica si ese pareo máximo es **perfecto** (cuando todos los vértices quedan emparejados y |U| = |V|).

---

## Algoritmo 2: Pareos perfectos y maximales en grafos no bipartitos (con restricciones)

Este programa trabaja con grafos generales (posiblemente dirigidos y/o ponderados) y calcula un **pareo maximal** usando un algoritmo greedy que recorre las aristas; después verifica si ese mismo pareo maximal resulta ser **perfecto**.  
No implementa el algoritmo de Edmonds (Blossom), por lo que **no garantiza** encontrar un pareo máximo ni un pareo perfecto aunque exista: solo asegura maximalidad.

### Cómo usarlo

1. Al correr el programa verás un menú donde puedes escoger:
   - **Capturar grafo**
   - **Calcular pareo maximal y verificar si es perfecto**
   - **Salir**
2. Si escoges **Capturar grafo** debes:
   - Ingresar número de vértices.
   - Ingresar número de aristas.
   - Indicar si es dirigido (1/0).
   - Indicar si es ponderado (1/0).
   - Ingresar las aristas:
     - Si no es ponderado: `u v`
     - Si es ponderado: `u v peso`
   - Para el pareo, el programa trata el grafo como **no dirigido** (ignora la dirección).
3. Con la opción de **pareo maximal** el programa:
   - Recorre las aristas en orden.
   - Toma una arista solo si ambos vértices están libres.
   - Imprime el pareo maximal y su tamaño.
   - Verifica si todos los vértices quedaron emparejados y si el número de vértices es par:
     - Si se cumplen estas condiciones, el pareo maximal es también un **pareo perfecto**.
     - Si no, indica que el pareo maximal **no es perfecto**.

> **Restricción importante:** al ser un algoritmo greedy en un grafo no bipartito, no se garantiza que el pareo obtenido sea máximo ni que encuentre un pareo perfecto aunque exista; para eso se requeriría un algoritmo más avanzado como el de Edmonds (Blossom).

---

## Como compilar y ejecutar (Tema 9)

Estando en la raíz del proyecto y usando `g++`:

**Algoritmo 1 – Pareos en grafos bipartitos**

```bash
g++ Tema9_Pareos_perfectos_y_maximales/1_Pareos_perfectos_bipartitos.cpp -o pareos_bipartitos
./1_Pareos_perfectos_bipartitos
```

O si ya tienes el ejecutable en Windows:

```bash
g++ Tema9_Pareos_perfectos_y_maximales/1_Pareos_perfectos_bipartitos.cpp -o pareos_bipartitos
./1_Pareos_perfectos_bipartitos.exe
```

**Algoritmo 2 – Pareos en grafos no bipartitos**

```bash
g++ Tema9_Pareos_perfectos_y_maximales/1_Pareos_perfectos_bipartitos.cpp -o pareos_bipartitos
./2_Pareos_perfectos_no_bipartitos
```

O si ya tienes el ejecutable en Windows:

```bash
g++ Tema9_Pareos_perfectos_y_maximales/1_Pareos_perfectos_bipartitos.cpp -o pareos_bipartitos
./2_Pareos_perfectos_no_bipartitos.exe
```