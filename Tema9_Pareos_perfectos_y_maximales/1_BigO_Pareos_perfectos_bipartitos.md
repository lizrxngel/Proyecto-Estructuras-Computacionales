# Pareos perfectos y maximales en grafos bipartitos

**Tema:** Pareos maximales y máximos (incluyendo perfectos) en grafos bipartitos.

**Algoritmos usados:**  
- Pareo maximal: algoritmo greedy sobre la lista de aristas.  
- Pareo máximo: algoritmo de Hopcroft–Karp para máximo pareo en grafos bipartitos.

**Complejidad (greedy):**  
- Tiempo: `O(m)`, donde `m` es el número de aristas, ya que se recorre la lista de aristas una sola vez.  
- Espacio: `O(n + m)`, donde `n` es el número de vértices, por la lista de aristas y los arreglos que marcan vértices usados.

**Complejidad (Hopcroft–Karp):**  
- Tiempo: `O(m * sqrt(n))`, aprovechando BFS y DFS para encontrar varios caminos aumentantes de longitud mínima en cada fase.  
- Espacio: `O(n + m)`, por la lista de adyacencia, las distancias y los arreglos de pareo.

**Explicación en un solo párrafo:**  
En el caso bipartito, el programa puede construir primero un pareo maximal mediante un algoritmo greedy que recorre la lista de aristas y empareja cada vez que ambos extremos están libres, obteniendo un pareo que ya no se puede extender con una sola arista, aunque no garantice ser de tamaño máximo. Para encontrar un pareo máximo, se utiliza Hopcroft–Karp: el grafo se representa con listas de adyacencia desde la parte izquierda hacia la derecha y se mantiene un pareo parcial entre U y V; mediante BFS se etiquetan niveles para identificar caminos aumentantes más cortos y luego, usando DFS, se amplía el pareo de manera simultánea a lo largo de varios de esos caminos. Este proceso se repite hasta que no hay más caminos aumentantes, obteniendo un pareo de cardinalidad máxima; si en un grafo bipartito con |U| = |V| el tamaño del pareo máximo es igual al número de vértices de cada lado, entonces el pareo es perfecto porque cubre todos los vértices.
