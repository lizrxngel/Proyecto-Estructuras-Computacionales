# Tema 6: Grafo bipartito

## Algoritmos 1 y 2: verificar si un grafo es bipartito usando multiplicación de matrices(1) y DFS(2) en C++

Estos programas permiten checar si un garfo es bipartito o no.

## Multiplicación de matrices
Este programa calcula las potencias impares de la matriz de adyacencia, si la diagonal de Aⁿ contiene valores mayores a cero, el grafo NO es bipartito.

### Cómo usarlo
1. Hay un menú donde puedes ecoger:
- Grafos predefinidos
- Ingresar tu propio grafo
- Salir
* Si escoges ingresar grafo debes:
- Ingresar número de vertices
- Ingresar número de aristas
- Ingresar conexiones (u v peso)


---
## DFS
Usa DFS recursivo para colorear los nodos (0 y 1), si alguna arista conecta dos nodos con el mismo color, el grafo NO es bipartito.

### Cómo usarlo
1. Hay un menú donde puedes ecoger:
- Grafos predefinidos
- Ingresar tu propio grafo
- Salir
* Si escoges ingresar grafo debes:
- Ingresar número de vertices
- Ingresar número de aristas
- Ingresar conexiones (u v peso)

---

## Como compilar

**Algoritmo 1**
Usando `g++`:
```bash
g++ 1_bipartito.cpp -o bipartito
./bipartito
```
O si ya tienes el ejecutable
```bash
./1_bipartito.exe
```

**Algoritmo 2**
Usando `g++`:
```bash
g++ 2_bipartito_DFS.cpp -o DFS
./DFS
```
O si ya tienes el ejecutable
```bash
./2_bipartito_DFS.exe
```