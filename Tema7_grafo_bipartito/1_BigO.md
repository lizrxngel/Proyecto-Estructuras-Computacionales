# Análisis Big O de primero algoritmo

## Tiempo:
- La multiplicación de matrices cuadradas toma O(V³) y se realiza dos veces por cada potencia impar buscada.
- El número de potencias revisadas es ≈ V/2, por lo que el tiempo total es O(V⁴).
- Construir la matriz y leer entradas cuesta O(V²).
Total: **O(V⁴)**

## Espacio
- Las matrices almacenadas ocupan O(V²) memoria.
- No se usa recursión, solo matrices auxiliares también de tamaño O(V²).
Total: **O(V²)**.