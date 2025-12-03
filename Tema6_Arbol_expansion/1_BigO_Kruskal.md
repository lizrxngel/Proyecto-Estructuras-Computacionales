# Análisis Big O de Algoritmo Krusal

## Tiempo
- Ordenar las E aristas mediante sort → O(E log E).
- Union-Find en cada arista con compresión de caminos y unión por rango → O(α(N)) ≈ O(1).
- Recorrer todas las aristas: O(E) adicional.
Total: **O(E log E).**

## Espacio
- Arreglo de aristas: O(E).
- Arreglo MST: O(E).
- Estructura Union-Find (padre, rango): O(N).
Total:  **O(E + N)**.