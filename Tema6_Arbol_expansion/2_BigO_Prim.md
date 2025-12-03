# Análisis Big O de Algoritmo de Prim

## Tiempo
- Inicializar arreglos: O(N).
- En cada iteración eliges el nodo con menor distancia mediante un ciclo completo: O(N).
- El ciclo principal corre N veces → N × O(N) = O(N²).
- Recorrer vecinos suma a lo mucho O(E).
Total: **O(N²)** 

## Espacio
- Matrices adyNodo y adyPeso de tamaño fijo 100×100: O(N²).
- Arreglos grado, dist, visitado, padre ⇒ O(N).
Total: **O(N²)**.