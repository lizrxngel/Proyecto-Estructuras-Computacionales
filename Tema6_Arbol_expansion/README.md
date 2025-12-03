## Tema 6: Árbol de expansión

## Algortimo 1 y algoritmo 2: Kruskal y Prim en C++

Estos programas construir un Árbol de Expansión Mínima. Este árbol conecta todos los nodos del grafo con el menor costo posible.

---

## Como usar el programa
### Kruskal
El código pide:
- Ingresar si quieres seleccionar un grafo, ejecutar el algoritmo, o salir.
1. Seleccionar grafo: puedes elegir entre grafo no dirigido y ponderado, grafo dirigido y ponderado, o ingresar grafo manualmente.
* Si decides ingresar manualmente te pedirá el número de vértices, el número de aristas, y las aristas con su peso (u v peso).
- Después ejecutas el algoritmo para encontrar el MST.

### Prim
El código pide:
- Ingresar si quieres capturar grafo manualmente o cargar uno predefinido.
* Si decides ingresar manualmente te pedirá el número de vértices, el número de aristas, y las aristas con su peso (u v peso).
- Después ejecutas el algoritmo para encontrar el MST.
---

## Cómo compilar

**Algoritmo 1**
Usando `g++`:
```bash
g++ 1_Kruskal.cpp -o kruskal
./kruskal
```
O si ya tienes el ejecutable
```bash
./1_Kruskal.exe
```

**Algoritmo 2**
Usando `g++`:
```bash
g++ 2_Prim.cpp -o prim
./prim
```
O si ya tienes el ejecutable
```bash
./2_Prim.exe
```