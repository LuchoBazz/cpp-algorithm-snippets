# :pushpin: Algorithms Template for Competitive Programming

Este repositorio contiene templates de algorimtos y estructuras de datos populares codificados en C++ para usar en competencias de programación.

## Contenido

* **Debugging**
    * `to_string_main` - metodo to_string de los principales tipos de datos y estructuras de datos estandard
    * `to_string_other` - metodo to_string de pairs, tuple y bitset

* **Geometry**
    * `2d_geometry_main` - todos los templates de geometria en 2D

* **Macros**
    * `macros_main` - Macros principales del template
    * `macros_numeric` - Macros para acortar los tipos de datos numericos
    * `macros_pairs` - Macros para acortar las tuples y pairs
    * `macros_precise` - Macros para acortar la precision de decimales
    * `macros_infinity` - Macros que define las constantes de infinito

* **Math**
    * `math_check_prime` - Test de Primalidad de un numero
    * `math_divisors` - Obtener todos los divisores de un numero
    * `math_gcd` - Maximo comun divisor
    * `math_lcm` - Minimo comun multiplo
    * `math_prime_factors` - Obtener los factores primos de un numero
    * `math_sieve` - Todos los numeros primos en un rango dado

* **Query Range**
    * `query_range_segment_tree` - Estructura de datos Segment Tree

* **Graph**
    * `graph_graph` - Clase padre de la representacion de un grafo
    * `graph_digraph` - Clase hijo que representa a un grafo dirigido
    * `graph_undigraph` - Clase hijo que representa a un grafo no dirigido
    * `graph_dijkstra_std` - Algoritmo de Dijkstra
    * `graph_dsu` - Estructura de datos Disjoint Set Union

* **Numeric**
    * `numeric_mint` - Template Completo de Aritmetica Modular
    * `numeric_mod` - Template de Aritmetica Modular Basica
    * `numeric_bigint` - Template Completo para hacer operaciones numericas con numeros muy grandes

* **Template**
    * `template_main` - C++ Template

## Creditos
 
* **Debugging**
    * Algunos componentes del codigo fuente de este folder fué extraido de [the-tourist/algo](https://github.com/the-tourist/algo) `misc > debug.cpp` ➡️ Por **Gennady Korotkevich (Tourist)**

* **Graph**
    * Algunos componentes del codigo fuente de `graph/graph_digraph.cpp`, `graph/graph_graph.cpp` y `graph/undigraph.cpp` fué extraido de [the-tourist/algo](https://github.com/the-tourist/algo) `graph > ...` ➡️ Por **Gennady Korotkevich (Tourist)**

* **Numeric**
    * Algunos componentes del codigo fuente de `numeric/numeric_mint.cpp` fué extraido de [the-tourist/algo](https://github.com/the-tourist/algo) `numeric > mint.cpp` ➡️ Por **Gennady Korotkevich (Tourist)**

    * Algunos componentes del codigo fuente de `numeric/bitint.cpp` fué extraido de [indy256/codelibrary](https://github.com/indy256/codelibrary) `numeric > bitint.cpp` ➡️ Por **Andrei Navumenka**