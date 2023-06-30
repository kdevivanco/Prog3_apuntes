## **31.5 Container Adaptors**

<aside>
📚 A container adaptor provides a different and restricted interface to a container.

These are intended to be used only through their specialized interfaces.

- STL container adaptors do not offer direct access to their underlying container.
- NO ITERATORS OR SUBSCRIPTING.

*C++ Programming Language*

</aside>

## std::stack

- En C++, `std::stack` es una estructura de datos que se utiliza para almacenar elementos de manera LIFO (último en entrar, primero en salir).
- El orden de los elementos es el inverso al orden en que se insertaron. Puedes utilizar esta estructura de datos para realizar operaciones de deshacer/rehacer en editores de texto, coincidencia de paréntesis en compiladores y lenguajes de programación, búsqueda en profundidad en grafos y árboles, y más.
- `#include <stack>`

**Aplicaciones:**

- Operaciones Deshacer-Rehacer en editores de texto, herramientas de desarrollo de software y software de diseño gráfico.
- Algoritmos de retroceso en inteligencia artificial y aprendizaje automático.
- Coincidencia de paréntesis en compiladores y lenguajes de programación.
- Búsqueda en profundidad en grafos y árboles.
- Evaluación de expresiones en notación postfija.
- Gestión de memoria en sistemas operativos.

![Captura de pantalla 2023-06-13 a la(s) 07.27.03.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/411e4b17-f2d7-42dd-96ca-c186fb4429f2/Captura_de_pantalla_2023-06-13_a_la(s)_07.27.03.png)

## std::queue

**std::queue**

En C++, `std::queue` es una estructura de datos que se utiliza para almacenar elementos de manera FIFO (primero en entrar, primero en salir). A diferencia de `std::stack`, en `std::queue` se pueden visualizar dos elementos: el de la cabeza y el de la cola. Tiene dos métodos adicionales: `.front()` y `.back()`. Puedes utilizar esta estructura de datos para realizar operaciones de gestión de memoria en sistemas operativos, procesamiento de tareas en cola y más.

![Captura de pantalla 2023-06-13 a la(s) 07.27.14.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9053b103-b403-4ac4-8ff2-58ed3ce940b9/Captura_de_pantalla_2023-06-13_a_la(s)_07.27.14.png)

**Aplicaciones:**

- Gestión de memoria en sistemas operativos.
- Procesamiento de tareas en cola.
- Sistemas de impresión.
- Simulación de eventos discretos.
- Procesamiento de paquetes de red.
- Almacenamiento de mensajes en un sistema de mensajería.
- Almacenamiento de procesos en un planificador de procesos.
- Sistemas de colas de llamadas.
- Procesamiento de archivos por lotes.
- Almacenamiento de eventos en un sistema de simulación.

Para utilizar la estructura de datos `std::queue`, es necesario incluir la biblioteca `#include <queue>`.

- FIFO
- A diferencia del stack, en caso de queue, se pueden visualizar dos elementos (el de la cabeza y el de atras - back)
- Tiene dos metodos adicionales → .front(), back()

Metodos:

| queque | priority_queue |  |
| --- | --- | --- |
| size() | size() |  |
| push(new_ob) | top() |  |
| front() | pop() |  |
| back() | push() |  |
|  |  |  |

## std::priority_queue

![Captura de pantalla 2023-06-13 a la(s) 07.29.20.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e1f8b4de-d4e2-442f-9e34-794d7298de24/Captura_de_pantalla_2023-06-13_a_la(s)_07.29.20.png)

- std::priority_queue<T> aqp
- Tiene un criterio de orden
- El criterio lo define el usuario
- En el caso del ejemplo → El criterio es los valores mayores
- Al igual que en el stack, solo se tiene visibilidad del top (primer valor)
- Cada vez que se inserta un elemento, se somete al criterio de orden - y se va a insertar donde cumpla ese criterio de orden
- En algunos caso se tiene que definir el criterio de orden
- (Parecido al map con compare - parametro de template)
- Usualmente se implementan usando la estructura heap
- priority_queue es un tipo de heap
- heap se usa para:
    - Priority queue
    - ordenamiento

### Grafos y árboles

- Algoritmos de grafos
    - Cuando se tienen estructuras de tipo árbol, o grafo → Se pueden tener muchas direcciones (mas que bidireccional)
    - Recorrido de la estructura → Recorrido a profundidad
    - Sistema operativo (stack)
    - Compiladores (Analizadores sintácticos)
    -