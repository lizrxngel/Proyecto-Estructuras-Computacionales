# Análisis Big O de Lista de Adyacencia

La lista guarda los vecinos que estan conectados a cada nodo.

- El espacio que ocupa es de **O(n+m)** donde m es el numero de aristas y n el de nodos.
- Insertar arista: **O(1)**.
- Eliminar arista: **O(deg(u))**.
- Comprobar si existe arista entre u y v: **O(deg(u))**.
---
### Observación: (deg(u)) se refiere al grado del nodo u, este es el caso ya que solo recorre la cantidad de nodos conectados a u (sus vecinos) y no recorre todos los nodos.
---
- Recorrer vecinos: **O(deg(u))**.
- Recorrer todas las aristas de un grafo: **O(n+m)**.
---
En este caso, la complejidad el algoritmo es de **O(n+m)**, ya que, aunque tiene un for anidado, no se recorren todos los nodos, sino solo aquellos conectados a u.
