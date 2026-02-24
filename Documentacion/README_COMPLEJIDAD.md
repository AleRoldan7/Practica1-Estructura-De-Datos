# Análisis de complejidad — Barajar y buscar cartas (resumen breve)

Archivo basado estrictamente en la implementación del proyecto (archivos analizados en `Uno/clases/...`). Solo se listan los tiempos de ejecución observables en el código — sin recomendaciones ni sugerencias.

## Barajar (mezclar mazo)

- `MazoCartas::revolverCartas()`
  - Implementación: mueve cartas entre pilas auxiliares (`aux`, `temp`) y hace rotaciones aleatorias usando `rand() % aux.sizeMazo()` para extraer cartas.
  - Complejidad temporal observada en el código: O(n^2) en tiempo esperado y en el peor caso (cada extracción puede implicar mover hasta O(n) elementos, repetido ~n veces).
  - Complejidad espacial observada: O(n) espacio adicional (pilas auxiliares que almacenan hasta n cartas).

- `MazoFlip::createMazoFlip()`
  - Implementación: construye dos `std::vector<Carta>` (ladoClaro y ladoOscuro) y aplica `std::shuffle` a cada uno; luego empareja entradas y empuja resultados a la pila `mazoFlip`.
  - Complejidad temporal observada: O(n) (cada `std::shuffle` y las operaciones de volcado/empate son lineales).
  - Complejidad espacial observada: O(n) (vectores temporales usados durante la creación).

- `MazoFlip::revolverCartaMazoFlip()`
  - Implementación: algoritmo análogo a `MazoCartas::revolverCartas()` (uso de `PilaFlip aux` y `PilaFlip temp` con saltos aleatorios).
  - Complejidad temporal observada: O(n^2) en tiempo esperado y peor caso.
  - Complejidad espacial observada: O(n) espacio adicional (pilas auxiliares).

Nota: en el código, el constructor de `MazoFlip` llama a `createMazoFlip()` (O(n)) y luego a `revolverCartaMazoFlip()` (O(n^2)), por lo que se realizan ambas operaciones.

## Robar carta (extraer del tope)

- `PilaMazo::pop()` / `PilaFlip::pop()` (usadas por `MazoCartas::robarCarta()` y `MazoFlip::robarCartaFlip()`)
  - Implementación: eliminación de la cabeza de una lista ligada.
  - Complejidad temporal: O(1) por operación `pop()`.
  - Complejidad espacial: O(1) adicional.

## Buscar / acceder a cartas en la mano (mano del jugador)

- `ListaMazoJugador` (lista ligada, `NodoMazo* nodo` y `cantidadCartas`)
  - Operaciones observadas en el código:
    - `insertarCartasOrdenada(Carta carta)`: recorre la lista hasta la posición de inserción — tiempo O(n) en el peor caso.
    - `jugarCarta(int posicionCarta)` / `obtenerCarta(int posicionCarta)` / `eliminarCarta(int posicionCarta)`: recorrido hasta la posición solicitada — tiempo O(k) para posición k, O(n) en el peor caso.
  - Búsqueda lineal por valor (si se implementa como recorrido): tiempo O(n), espacio O(1).

- `ListaMazoFlipJugador` (lista ligada, `NodoManoFlip* head` y `cantidad`)
  - Operaciones observadas en el código:
    - `insertarOrdenado(const CartaFlip& carta)`: recorre hasta la posición de inserción — O(n) en el peor caso.
    - `obtenerCartaFlip(int posicion)` / `eliminarCartaFlip(int posicionCarta)`: recorrido hasta la posición — O(k) para la posición k, O(n) peor caso.
  - Búsqueda por valor (si se realiza por recorrido): O(n) tiempo, O(1) espacio.

## Resumen rápido (solo tiempos extraídos del código)
- Barajar:
  - `MazoCartas::revolverCartas()` — O(n^2) tiempo, O(n) espacio adicional.
  - `MazoFlip::createMazoFlip()` — O(n) tiempo, O(n) espacio temporal (usa `std::shuffle`).
  - `MazoFlip::revolverCartaMazoFlip()` — O(n^2) tiempo, O(n) espacio adicional.
- Robar carta (`pop`) — O(1) tiempo.
- Buscar / acceder en mano (listas ligadas) — O(n) tiempo en general para búsquedas y operaciones por índice; O(1) para obtener tamaño.

