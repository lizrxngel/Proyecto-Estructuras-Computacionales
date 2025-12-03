# Tema 5: Comprobar si grafo es árbol o no.

Los siguientes programas permiten comprobar si un grafo es árbol o no.

## Programa 1: DFS

Como ya mencionado anteriormente, en grafos dirigidos DFS calcula componentes débilmente conexas, o sea, conecta aristas sin considerar su direccion. Sin embargo, en grafos ponderados se debe tener en cuenta que cada nodo puede tener multiples nodos adyacentes con diferentes costos, necesitando la implementacion de una pila o recursividad para obtener el camino más corto.

# Como usar los programas
Los códigos piden:
    1. Número de nodos 
    2. Número de aristas
    3. Saber si es dirigido o no (1 para si, 0 para no).
    4. Saber si es ponderado o no (1 para si, 0 para no).
    5. Te pide que escogas que quieres que muestre, si es dirigido, si es ponderado o si es árbol.

---

## Programa 2: BFS con propiedades.

Para verificar si un grafo es un árbol se comprueban las siguientes propiedades fundamentales:
    1. Es NO dirigido
    2. Un árbol con N nodos tiene exactamente N-1 aristas.
    3. Es conexo, es decir, para todo par de nodos hay al menos una arista conectandolos.

BFS permite recorrer niveles de del grafo y determina qué nodos son alcanzables desde un nodo raíz, por lo que haciendo uso de eso y de las propiedades mencionadas, se puede determinar si un grafo es árbol o no.
