# 1) Pareo maximal en grafo general

**Tema:** Pareo maximal en grafo general (dirigido / no dirigido, ponderado / no ponderado).

**Algoritmo usado:**  
Greedy sobre lista de aristas.

---

## Complejidad

- **Tiempo:**  
  - `O(m)`, donde `m` es el número de aristas.  
  - Se recorre la lista de aristas una sola vez y se decide si se toma cada arista o no.

- **Espacio:**  
  - `O(n + m)`, donde `n` es el número de vértices.  
  - Se guarda la lista de aristas y un arreglo `usado` de tamaño `n`.

---

## Idea de funcionamiento

El algoritmo lee el grafo (aunque sea dirigido y/o ponderado) pero para el pareo lo interpreta como no dirigido, luego inicializa un arreglo `usado` para marcar qué vértices ya fueron emparejados y recorre la lista de aristas en el orden en que se introdujeron; para cada arista `(u, v)` revisa si ambos vértices están libres y, en caso afirmativo, la añade al pareo y marca `u` y `v` como usados para que no vuelvan a emparejarse. Al terminar de revisar todas las aristas ya no es posible agregar ninguna arista más al pareo sin reutilizar vértices, por lo que el pareo obtenido es maximal (no necesariamente el de mayor tamaño posible, pero sí uno que no se puede extender con una sola arista adicional).
