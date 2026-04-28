## Actividad 3-CC232

### Estudiante

- Nombre: Oscar Alberto Pomalia Suyo

#### Bloque 1

1. El cambio es de una representación basada en un bloque continuo de memoria a una representación basada en nodos enlazados; eso modifica cómo accedes, cómo insertas/borras y cómo afecta el costo y el uso de memoria.
2. -rango = índice directo en memoria contigua;
   -posición/enlace = recorrido explícito de nodos en estructuras dinámicas enlazadas.
3. La lista enlazada es buena para cambios locales cuando ya conoces el nodo donde operar. Pero si necesitas acceder a un elemento por su índice numérico, pierdes la ventaja de acceso directo y terminas recorriendo nodos.
4. Ambas estructuras aprovechan operaciones en los extremos, SLList mantiene acceso rápido al primer nodo (head) y al último nodo (tail), las operaciones requeridas son O(1) porque solo actualizan punteros de uno o dos nodos, sin recorrer la lista completa.
5. SLList es eficiente en un extremo (el frente) y puede ser eficiente en el otro extremo para inserción si guarda tail, pero no puede manejar simétricamente todas las operaciones de un Deque con el mismo costo porque le falta el enlace hacia atrás.
6. El dummy actúa como un "ancla" que permite operaciones consistentes en una lista doblemente enlazada, facilitando la implementación sin lógica extra para casos límite.
7. El método getNode(i) navega eficientemente: si i < n/2, avanza desde el inicio (dummy.next) i pasos; si no, retrocede desde el final (&dummy) n-i pasos. Esto toma O(min(i, n-i)) tiempo. Una vez localizado el nodo, las operaciones son O(1): get y set acceden/modifican directamente; add usa addBefore para insertar antes del nodo; remove usa removeNode para eliminar y ajustar punteros. El 1 representa la operación constante después de la navegación, aprovechando los enlaces bidireccionales para minimizar el recorrido.
8. Es un trade-off entre acceso (mejor que lista pura) y espacio (mejor que arreglo puro), con complejidad amortizada O(b) para operaciones locales.
9. Porque simplifica la implementación, aprovechando la eficiencia de arreglos para acceso y la flexibilidad de deques para actualizaciones.
10. No reemplaza a las estructuras de Morin (SLList, DLList, SEList) porque estas se centran en representaciones específicas con costos optimizados para operaciones básicas (e.g., DLList para acceso bidireccional eficiente, SEList para trade-off espacio-acceso). DengList es complementaria: se usa vía MorinDengBridge para aplicar algoritmos genéricos sin reescribir lógica estructural, permitiendo reutilización pero manteniendo las ventajas de cada representación. Es una separación de concerns entre estructura y algoritmos.
 
#### Bloque 2

1. add(10) y add(20) se comportan como cola (enqueue al final). push(5) se comporta como pila (inserta al frente). pop() elimina el primer elemento, como una pila o una cola con acceso al frente. remove() también quita del frente, mostrando que la lista usa head para desencolar.
2. La operación que mejor muestra la inserción en posición intermedia es:

d.add(1, 20);

Porque inserta 20 entre 10 y 30, dejando la lista como 10 20 30. Eso es exactamente un ejemplo de inserción en el medio.
3. El observable es la salida del for que recorre s.size() y hace s.get(i) en orden. Aunque SEList internamente usa bloques, el demo imprime los valores en secuencia lógica 0 10 20 ... 90. Eso muestra que la vista externa conserva el orden lineal esperado.
4. lista.push_back(30) / push_back(10) / push_back(20) muestra inserciones al final. 
lista.push_front(5) muestra inserción al frente.
lista.front() y lista.back() muestran acceso a ambos extremos.
lista.sort() muestra una operación algorítmica de lista más rica que no está en SLList/DLList básico.
lista.to_vector() muestra que la lista tiene una interfaz completa para obtener su contenido en orden.
5. cc232::stable_sort_with_deng(lista);
int removed = cc232::dedup_with_deng(lista);
luego imprime DLList reforzada con Deng: ... y Removido = ...
Eso justifica la reutilización porque la salida muestra que la DLList original fue ordenada y deduplicada usando operaciones de Deng sin cambiar la implementación base de DLList. La estructura sigue siendo DLList, pero el puente aplica algoritmos de DengList para producir la lista ordenada y depurada.
6. No basta con guardar los valores; las estructuras “min” guardan metadatos extra para poder responder min() en tiempo constante.
7. El mejor adaptador es LinkedStack.

LinkedStack reutiliza directamente SLList como almacenamiento interno.
Ofrece una interfaz nueva de pila (push, pop, top) sobre una lista simple.
El demo muestra claramente que la misma estructura base puede dar la semántica de un stack sin reimplementar nodos.
8. Acceso por índice: ArrayDeque.get(4) y DLList.get(4) devuelven el mismo valor, pero la representación contigua es la que realmente explota el acceso por índice de forma natural y con mejor locality.
Inserción local: la salida y el código contrastan que la representación enlazada (LinkedQueue / LinkedDeque / DLList) es la que “facilita inserciones/borrados locales”.
Localidad de memoria: el demo dice explícitamente que la representación contigua ofrece mejor localidad de memoria, lo que es una ventaja frente a la lista enlazada.

#### Bloque 3

1. Para SLList el test público valida estas operaciones mínimas:

add(x) en el final de la lista
push(x) al frente
size()
peek() del elemento del frente
pop() del frente
remove() del frente
2. Para DLList la prueba pública valida estas operaciones mínimas:

add(i, x) en posiciones específicas
d.add(0, 10)
d.add(1, 30)
d.add(1, 20)
size()
get(i) en índices 0, 1 y 2
remove(1)
3. Para SEList la prueba pública valida estas operaciones mínimas:

creación de SEList<int> s(3) con tamaño de bloque b = 3
add(i, x) en posiciones crecientes (s.add(i, i) para i = 0..9)
size()
get(i) en índice medio (s.get(5))
set(i, x) en índice medio (s.set(5, 50))
remove(i) en índice medio (s.remove(5))
4. SLList:
-add(1, 20) inserción en posición intermedia
-to_vector()
-secondLast()
-reverse()
-checkSize()
DLList:
-rotate(1)
-to_vector()
-isPalindrome()
-checkSize()
MinStack:
-push()
-min()
-pop()
MinQueue
-add()
-remove()
-front()
-min()
MinDeque:
-addFirst()
-addLast()
-front()
-back()
-removeLast()
-min()
XorList:
-push_back()
-push_front()
-to_vector()
-reverse()
5. LinkedStack:
-empty() inicial
-push(x) varias veces
-size()
-top()
-pop()
-empty() final
LinkedQueue:
-empty() inicial
-add(x) varias veces
-size()
-front()
-remove() varias veces
-empty() final
LinkedDeque:
-empty() inicial
-addFirst(x) y addLast(x)
-size()
-front() y back()
-removeFirst() y removeLast()
-empty() final
6. Valida la integración de una capa de algoritmo común (Deng) con las estructuras base de Morin, mostrando que se puede aplicar ordenamiento, eliminación de duplicados y reversa a diferentes implementaciones usando el mismo puente/reutilización.
7. Crecimiento con muchas inserciones al principio: s.add(i, i) 500 veces en posición 0
borrado repetido del frente: s.remove(0) 250 veces
re-inserciones adicionales al frente: s.add(i, -i) 100 veces
verificación del tamaño lógico final: assert(s.size() == 350)
8. Prueba que la lista enlazada funciona correctamente para las secuencias específicas de uso que cubre el test.
9.Una prueba pública demuestra solo que algunos ejemplos específicos funcionan; no reemplaza entender el diseño, las invariantes, los punteros y la complejidad.
10. Los tests confirman comportamiento puntual; la explicación de invariantes, punteros y complejidad es la que justifica que la estructura es correcta, segura y eficiente en general.

#### Bloque 4

- **reverse() en SLList:** Me pareció fascinante cómo se puede invertir la lista en una sola pasada usando tres punteros temporales para "voltear las flechas" sin crear una lista nueva.
- **isPalindrome() en DLList:** Aprovecha que podemos caminar desde ambos extremos hacia el centro simultáneamente, comparando los valores en $O(n/2)$.
- **Location en SEList:** Es la "dirección" de un dato: en qué bloque vive y en qué posición del arreglo interno se encuentra.

#### Bloque 5

- `LinkedStack` y `LinkedQueue` simplemente redirigen sus llamadas a una `SLList` interna. Es un gran ejemplo de **reutilización de código**.
- `MinQueue` usa dos stacks para simular el comportamiento de cola y mantener el rastro del mínimo en $O(1)$ amortizado.

#### Bloque 6

1. Ordenamiento (`sort`), eliminación de duplicados (`deduplicate` / `uniquify`) e inversión (`reverse`).
2. Separa responsabilidades. Morin maneja el core de la memoria, y Deng aporta algoritmos avanzados sin ensuciar ni reescribir el código base.
3. `to_deng` envuelve la lista original para que pueda usar los algoritmos. `assign_from_deng` toma los resultados procesados y los devuelve a la lista base.
4. Extrae los datos, los ordena usando la lógica genérica de Deng, y los reinyecta. La lista original no necesita saber cómo ordenarse a sí misma.
5. Elimina nodos adyacentes iguales, reduciendo el tamaño en $O(n)$. Generalmente requiere que la lista esté ordenada previamente.
6. La lógica de cambiar punteros para invertir se escribe una sola vez en el adaptador y sirve para cualquier estructura subyacente que use esa API.
7. Introduce un costo de copia/movimiento $O(n)$. Vale la pena cuando la ganancia algorítmica (ej. un `sort` eficiente) compensa este costo.

#### Bloque 7

1. `ArrayDeque` usa un arreglo contiguo circular que sufre pausas costosas de `resize()`. `LinkedDeque` usa nodos, asegurando $O(1)$ constante pero sin beneficios de caché.
2. Significa que, al estar físicamente adyacentes en la RAM, la CPU puede cargar bloques enteros a la memoria caché L1/L2 (Prefetching), siendo extremadamente rápido de leer.
3. Inserciones masivas en el medio de la colección o uniones (splicing) de dos listas muy grandes.
4. Para acceso aleatorio, medir ráfagas de `get(i)`. Para extremos, alternar operaciones de simulación de colas.
5. Porque el tiempo de ejecución en milisegundos depende del hardware del alumno, carga del SO y optimizaciones del compilador en ese momento.
6. Intenta simular una lista doblemente enlazada usando un solo "pseudo-puntero" calculado con la operación XOR entre las direcciones vecinas.
7. Es insegura, muy difícil de depurar y hace que los algoritmos de Garbage Collection fallen por no tener punteros explícitos.

#### Bloque 8 

Pasar de arreglos a estructuras enlazadas es cambiar velocidad de acceso por flexibilidad. En los arreglos el acceso es instantáneo ($O(1)$) pero mover datos es costoso. En las listas enlazadas (`SLList`, `DLList`), el acceso es lento ($O(n)$) pero las inserciones son quirúrgicas y baratas. La `SEList` es el punto medio que intenta darnos lo mejor de ambos mundos. Los adaptadores cierran el círculo permitiendo que estas estructuras complejas se comporten como herramientas simples (Pilas/Colas) para resolver problemas reales.

#### Autoevaluación breve

- Qué puedo defender con seguridad: Entiendo bien el relinkeo de punteros en DLList y el uso de centinelas.
- Qué todavía confundo: A veces me mareo un poco con los índices de los bloques en SEList.
- Qué evidencia usaría en una sustentación: Usaría la demo de `reverse()` para mostrar cómo manipulo punteros físicamente.

