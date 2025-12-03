# Análisis Big O de algoritmos para encontrar Componentes Conecas

## DFS y BFS
Ambos algoritmos tienen la misma complejidad, que ya fue analizada en el tema dos, para el análisis completo ir a: [Análisis BigO DFS/BFS](https://github.com/lizrxngel/Proyecto-Estructuras-Computacionales/blob/main/Tema2_Recorrido_de_grafos/BigO.md)

---

## Algoritmo de Tarjan 
- Este algoritmo también tiene la misma complejidad bigO de **O(V + E)** que DFS y BFS.

*Recordemos que V = nodo y E = arista*

- Cada nodo se visita una sola vez: **O(V)**
- Cada arista se examina una vez: **O(E)**
- Insertar/quitar de la pila: **O(1)**

Por lo que la complejidad es de **O(V + E)**.

Este algoritmo es eficiente ya que solo ocupa una DFS.

