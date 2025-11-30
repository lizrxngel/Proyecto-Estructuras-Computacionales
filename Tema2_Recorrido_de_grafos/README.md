## Tema 2: Recorrido de grafos

## Algortimo 1 y algoritmo 2: BFS Y DFS en C++

- BFS (Breadth-First Search): recorre el grafo por niveles, es decir, recorre los vecinos del nodo antes de ir más profundo.
- DFS(Depth-First Search): recorre el grafo en profundidas, primero explora el camino más profundo antes de retroceder.

Ambos algoritmos funcionan sobre grafos dirigidos, no dirigidos, ponderados, y no ponderados (las ponderaciones no afectan el recorrido).
---
## Como usar el programa
El código pide:
1. Número de nodo -> ingresar la cantidad de nodos del grafo
2. Tipo de grafo -> 1.No dirigido y 2.Dirigido, ingresar 1 o 2 dependiendo de la elección
3. Tipo de ponderación -> 1.No ponderado y 2.Ponderado, ingresar 1 o 2 dependiendo de la elección
4. Numero de aristas -> ingresar la cantidad de aristas del grafo
5. Lista de aristas -> aquí hay 4 casos, ingresar lista según el caso:
- **No dirigido y no ponderado**: u v
- **No dirigido y ponderado**: u v peso
- **Dirigido y no ponderado**: u v
- **Dirigido y ponderado**: u v peso

u y v siendo los nodos a conectar por la arista, y peso el peso de la arista si es que es ponderado
---

## Cómo compilar

**Algoritmo 1**
Usando `g++`:
```bash
g++ 1_BFS.cpp -o bfs
./bfs
```
O si ya tienes el ejecutable
```bash
./1_BFS.exe
```

**Algoritmo 2**
Usando `g++`:
```bash
g++ 2_DFS.cpp -o dfs
./dfs
```
O si ya tienes el ejecutable
```bash
./2_DFS.exe
```