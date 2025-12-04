# Análisis Big O de BFS Y DFS

Ambos algoritmos tienen la misma complejidad
---
V = número de nodos
E = número de aristas
---
- Uso de cola: **O(V)**. 
- Cada arista se examina una vez: **O(E)**.

Complejidad **O(V + E)**.

## DFS
- Cada nodo se visita una vez: **O(V)**.
- Cada arista se examina una vez: **O(E)**.

Complejidad **O(V + E)**.

---
**NOTA ->** 
1. Debemos de tener en cuenta que en BFS y DFS no afecta si un grafo es ponderado o no, para conocer los caminos más cortos con ponderaciones se deben de usar otros algoritmos.
2. No hay ningún problema al usar DFS o BFS en grafos no dirigidos, pues se puede accesar a todos los nodos desde cualquier punto, sin embargo, al usar un grafo dirigido, puede que no se exploren todos los nodos, pues se sigue una dirección y esto no asegura que todos los nodos puedan ser visitados.
>>>>>>> main
