# Análisis Big O de Matriz de Adyacencia

- La matriz es de tamaño dijo de **nxn**, n siendo la cantidad de nodos.

- Insertar arista: **O(1)**.
- Eliminar arista: **O(1)**.
- Comprobar si esite una arista entre u y v: **O(1)** ya que se accede directamente a la celda.
- Recorrer vecinos de un nodo: **O(n)**
- Recorrer todas las aristas del grafo: **O(n^2)** ya que es un for anidado donde se recorren todos los nodos.

---
Como la notacion Big O siempre toma el peor caso posible, la complejidad de este algoritmo es de **O(n^2)**,