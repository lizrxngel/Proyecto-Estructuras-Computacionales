# 2) Pareo máximo con algoritmo Húngaro

**Tema:** Pareo máximo (de costo) en grafo bipartito completo, modelado como matriz de costos.

**Algoritmo usado:**  
Algoritmo Húngaro para el problema de asignación.

**Tiempo:**  
O(n³), donde `n` es el número de vértices en cada lado (matriz `n × n`).

**Espacio:**  
O(n²), por almacenar la matriz de costos y las estructuras auxiliares (`u`, `v`, `p`, `way`, etc.).

**Idea de funcionamiento (en un solo párrafo):**  
El grafo bipartito se representa como una matriz de costos `costo[i][j]`, donde `i` corresponde a una fila (parte izquierda) y `j` a una columna (parte derecha); el algoritmo mantiene potenciales para filas y columnas (`u` y `v`) y una asignación parcial `p` que indica qué fila está emparejada con cada columna. Para cada fila, se busca iterativamente la mejor columna disponible mediante costos reducidos `costo[i][j] - u[i] - v[j]`, actualizando etiquetas mínimas y construyendo un camino alternante que permite mejorar la asignación. Al finalizar, cada fila queda emparejada con exactamente una columna de forma que el costo total es mínimo; si se quiere un pareo de costo máximo, se transforman los valores originales (por ejemplo `costo' = maxValor - costo`) y se aplica el mismo procedimiento, recuperando después el costo original máximo.
