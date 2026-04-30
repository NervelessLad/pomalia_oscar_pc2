# Arquitectura de AllOne (LeetCode 432)

Para garantizar la complejidad estricta de O(1) en todas las operaciones, la estructura `AllOne` utiliza el patrón de diseño de **Tabla Hash + Lista Doblemente Enlazada (HashMap + DLList)**.

## 1. Componentes Principales

- **DLList (Lista Doblemente Enlazada):**
  Actúa como la columna vertebral. Cada nodo de la lista representa un `Bucket` de frecuencia.
  - Se utilizan nodos centinela (`head` y `tail`) con frecuencia 0 para eliminar los casos borde (inserciones/eliminaciones en los extremos).
  - La lista se mantiene estrictamente ordenada: el bucket más cercano a `head` tiene la frecuencia mínima, y el más cercano a `tail` tiene la frecuencia máxima.

- **HashMap (`std::unordered_map`):**
  Mapea una llave (ej. `"manzana"`) directamente a su `Bucket` correspondiente en la memoria. Esto permite acceder al nodo en O(1) sin tener que recorrer la lista enlazada.

## 2. Representación Visual en Memoria

```text
[ HashMap ]
"apple"  ------> (Apunta al Bucket Freq 2)
"banana" ------> (Apunta al Bucket Freq 1)
"kiwi"   ------> (Apunta al Bucket Freq 1)

[ Lista Doblemente Enlazada (Buckets ordenados) ]
          +-----------+      +-----------+      +-----------+      +-----------+
          |   HEAD    |      | Bucket 1  |      | Bucket 2  |      |   TAIL    |
NULL <--- | (Dummy)   | <--> | Freq: 1   | <--> | Freq: 2   | <--> | (Dummy)   | ---> NULL
          | Freq: 0   |      | keys:     |      | keys:     |      | Freq: 0   |
          +-----------+      | {banana,  |      | {apple}   |      +-----------+
                             |  kiwi}    |      +-----------+
                             +-----------+