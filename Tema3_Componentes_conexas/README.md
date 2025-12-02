## Tema 2: Componentes conexas

## Algortimo 1 y algoritmo 2: BFS y Dfs para encontrar componentes conexas, algoritmo de Tarjan para encontrar componentes Fuertemente Conexas en C++

Estos programas permiten ver los componentes conexa de un grafo:
## Usando BFS y DFS
En grafos **no dirigidos**, un componente conexa es aquel conjunto de nodos donde se puede acceder a ellos entre sí.
En grafos **dirigidos**, BFS y DFS calcula componentes *débilmente conexas*, es decir, conecta aristas sin considerar su dirección.

### Como usar el programa
El código pide:
1. Número de vertices
2. Número de aristas
3. Si es dirigido o no
4. Las aristas conectadas (u v)
5. Y el método de preferencia para encontrar componentes, ya sea DFS o BFS.

---
## Algoritmo de Tarjan
En este algoritmo, pueden usarse tanto grafos **dirigidos** como **no dirigidos**, sin embargo, este es un algoritmo planeado para usarse en grafos dirigidos, pues con los no dirigidos simplemente va a devolver lo que ya se encontró usando BFS o DFS, perdiendo el propósito.

Este algoritmo asigna un índice a cada nodo, calcula un "low-link" que calcula que tanto puede regresar en el DFS, usa una pila para identificar los componentes fuertemente conexas, y cada vez que llega al inicio de un ciclo, extrae los nodos de ese ciclo, que son los que están fuertemente conectados.

### Como usar el programa
El código pide:
1. Número de vertices
2. Número de aristas
3. Si es dirigido o no
4. Las aristas conectadas (u v)

---

## Cómo compilar

**Algoritmo 1**
Usando `g++`:
```bash
g++ 1_componentes_conexos_DFS_BFS.cpp -o componentes
./componentes
```
O si ya tienes el ejecutable
```bash
./1_componentes_conexos_DFS_BFS.exe
```

**Algoritmo 2**
Usando `g++`:
```bash
g++ 2_AlgoritmoTarjan.cpp -o Tarjan
./Tarjan
```
O si ya tienes el ejecutable
```bash
./2_AlgoritmoTarjan.exe
```