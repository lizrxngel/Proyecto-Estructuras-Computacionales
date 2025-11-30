## Tema 1: Representación de grafos

## Algortimo 1 y algoritmo 2: Matriz de adyacencia y lista de adyacencia en C++

Estos programas permiten crear y representar la **matriz de adyacencia** y la **lista de adyacencia**de un grafo según el usuario lo pida, puede escoger entre:

- Grafo **dirigido** o **no dirigido**
- Grafo **ponderado** o **no ponderado**
- Número arbitrario de nodos y aristas

- Matriz de adyacencia creada dinámicamente usando `vector<vector<int>>`
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
g++ Tema1_MatrizAdyacencia.cpp -o matriz
./matriz
```
O si ya tienes el ejecutable
```bash
./Tema1_MatrizAdyacencia.exe
```

**Algoritmo 2**
Usando `g++`:
```bash
g++ Tema1_ListaAdyacencia.cpp -o lista
./lista
```
O si ya tienes el ejecutable
```bash
./Tema1_ListaAdyacencia.exe
```
