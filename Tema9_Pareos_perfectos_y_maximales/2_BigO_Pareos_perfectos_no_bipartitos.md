# Pareos perfectos y maximales en grafos no bipartitos

**Tema:** Pareos maximales y detección de pareos perfectos en grafos no bipartitos.

**Algoritmo usado:**  
Algoritmo greedy para obtener un pareo maximal, con verificación posterior de si el resultado es perfecto.

**Complejidad:**  
- Tiempo: `O(m)`, ya que se recorre la lista de aristas una sola vez, tomando una arista solo cuando ambos vértices están libres.  
- Espacio: `O(n + m)`, por la lista de aristas y el arreglo de marcaje de vértices usados.

**Explicación en un solo párrafo:**  
En un grafo no bipartito, el programa lee la lista de aristas (ignorando la dirección si el grafo era dirigido) y aplica un algoritmo greedy que va recorriendo las aristas en el orden dado, añadiendo una arista al pareo solamente si ambos extremos están todavía libres, y marcando esos vértices como usados para no reutilizarlos; de esta forma se obtiene un pareo maximal, es decir, uno que no se puede extender agregando una sola arista más. Luego se verifica si todos los vértices quedaron emparejados y si el número de vértices es par, en cuyo caso el pareo obtenido es perfecto porque cubre todo el conjunto de vértices; sin embargo, debido a la naturaleza greedy del algoritmo, en grafos no bipartitos no se garantiza que el pareo producido sea máximo ni que encuentre un pareo perfecto aunque exista, ya que para eso se requeriría un algoritmo más sofisticado como el de Edmonds (Blossom).
