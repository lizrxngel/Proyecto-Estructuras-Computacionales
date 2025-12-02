# Análisis Big O de BFS Y DFS

Ambos algoritmos tienen la misma complejidad
---
V = número de nodos
E = número de aristas
---

## DFS
### Tiempo:
- Visita cada vértice una vez: O(V)
- Recorre cada arista una vez: O(E)
Total: **O(V + E)**

### Espacio:
- Pila de recursión o stack interno: O(V)
Total: **O(V)**

---
## BFS
### Tiempo:
- Igual que DFS: visita vértices y aristas una vez
Total: **O(V + E)**

### Espacio:
- Cola para almacenar nodos: O(V)
Total: **O(V)**
