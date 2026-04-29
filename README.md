## PC2 - CC232

### Estudiante
- Nombre: Oscar Alberto Pomalia Suyo
- Código: 20240385I
- Problema asignado: LeetCode 432 - All O`one Data Structure
- Enlace: https://leetcode.com/problems/all-oone-data-structure/

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal
- Semana: Semana 3
- Estructura o técnica principal: Memoria Enlazada, Lista Doblemente Enlazada (DLList) con Nodos Centinela (Dummy) combinada con HashMap.

### Resumen de la solución
La solución implementa una estructura compuesta. Un HashMap (`std::unordered_map`) permite ubicar cualquier llave en O(1). Las llaves se agrupan por frecuencia dentro de "Buckets" (nodos de una lista doblemente enlazada). Al incrementar o decrementar una llave, esta se mueve de su Bucket actual al adyacente (creando o destruyendo Buckets dinámicamente si es necesario). Esto permite que el Bucket con la menor frecuencia siempre esté justo después del nodo `head`, y el Bucket con la mayor frecuencia justo antes del nodo `tail`, garantizando respuestas en O(1).

### Complejidad
- Tiempo: O(1) estricto para las 4 operaciones (`inc`, `dec`, `getMaxKey`, `getMinKey`).
- Espacio: O(N) donde N es el número de llaves únicas insertadas, almacenadas tanto en la Tabla Hash como en los conjuntos internos de cada Bucket.

### Invariante o idea clave
- La Lista Doblemente Enlazada siempre se mantiene estrictamente ordenada de menor a mayor frecuencia.
- No existen Buckets vacíos en la lista (salvo los nodos centinela `head` y `tail`). Si un Bucket se queda sin llaves, se elimina inmediatamente y los punteros de sus vecinos se relinkean.

### Archivos relevantes
- include/
- src/
- tests/
- demos/

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución
```./build/tests
```

### Casos de prueba
Describe al menos 3 casos:
1.
2.
3.

### Historial de commits
Indica que el historial debe verse en el video.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.