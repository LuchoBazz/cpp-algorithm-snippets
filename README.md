# :pushpin: Algorithms Template for Competitive Programming

Este repositorio contiene templates de algorimtos y estructuras de datos populares codificados en C++ para usar en competencias de programación.

## Contenido

* **Misc**
    * **Debugging**
        * `to_string_main` - metodo to_string de los principales tipos de datos y estructuras de datos estandard
        * `to_string_other` - metodo to_string de pairs, tuple y bitset

    * **Misc**
        * `misc_main` - Macros principales del template
        * `misc_data_types` - Macros para acortar los tipos de datos numericos
        * `misc_pairs` - Macros para acortar las tuples y pairs
        * `misc_precise` - Macros para acortar la precision de decimales
        * `misc_infinity` - Macros que define las constantes de infinito
        * `misc_loops` - Macros para acortar los loops
        * `misc_min_max` - funciones min y max por referencia
        * `misc_directions` - Array con los valores para explorar una cuadricula 2D
        * `misc_reference` - Macros para acurtar el codigo de las referencias de un vector y fill un array
        * `misc_math` - Algunas constantes y funciones matematicas
        * `misc_vector_n_d` - Funciones para acortar la creacion de un vector de 2,3 y 4 dimensiones
        * `misc_cond` - Funciones y macros para acortar condiciones

* **Geometry**
    * `2d_geometry_point` - Estructura Point
    * `2d_geometry_area` - Algoritmo que calcula el area de un poligono
    * `2d_geometry_perimeter` - Algoritmo que calcula el perimetro de un poligono
    * `2d_geometry_convex_hull_mc` - Algoritmo de Convex Hull (Monotone Chain)

* **Math**
    * `math_check_prime` - Test de Primalidad de un numero
    * `math_divisors` - Obtener todos los divisores de un numero
    * `math_gcd_recursive` - Maximo comun divisor (Implementación Recursiva)
    * `math_gcd_iterative` - Maximo comun divisor (Implementación Iterativa)
    * `math_lcm` - Minimo comun multiplo
    * `math_prime_factors` - Obtener los factores primos de un numero
    * `math_sieve` - Todos los numeros primos en un rango dado
    * `math_is_power_of_n` - Algoritmo que verifica si un numero es potencia de `n`
    * `math_matrix` - Clase que representa a una matrix 2D con sus operaciones matriciales
    * `math_fft` - Algoritmo de Fast Fourier Transform (fft)
    * `math_polynomial` - Clase Polinomio con las siguientes Operaciones (Suma, Resta, Multiplicación, Division y Modulo)

* **Query Range**
    * `query_range_segment_tree` - Estructura de datos Segment Tree
    * `query_sum_range_immutable` - Consultas de suma en rangos (Immutable)

* **Graph**
    * `graph_graph` - Clase padre de la representacion de un grafo
    * `graph_digraph` - Clase hijo que representa a un grafo dirigido
    * `graph_undigraph` - Clase hijo que representa a un grafo no dirigido
    * `graph_dijkstra_std` - Algoritmo de Dijkstra
    * `graph_dsu` - Estructura de datos Disjoint Set Union
    * `graph_toposort_dfs` - Algoritmo de ordenamiento topologico usando dfs
    * `graph_kruskal` - Algoritmo de Kruskal (Minimo Arbol de Expansión)
    * `graph_scc_kosaraju` - Algoritmo de Kosaraju para buscar los Componentes fuertemente conexos (SCC)

* **Numeric**
    * `numeric_mint` - Template Completo de Aritmetica Modular
    * `numeric_mod` - Template de Aritmetica Modular Basica
    * `numeric_bigint` - Template Completo para hacer operaciones numericas con numeros muy grandes

* **String**
    * `string_suffix_array` - Algoritmo de Suffix Array
    * `string_kmp` - Algoritmo Knuth-Morris-Pratt (KMP)
    * `string_lps` - Mas grande prefijo que es tambien sufijo (Longest prefix suffix)
    * `string_trie` - Estructura de datos Arbol de Prefijos Trie (Prefix Tree)
    * `string_split` - Función split

* **Random**
    * `random_init` - Generar valor aleatorio en un rango
    * `random_permutation` - Generar permutación aleatoria
    * `random_vector` - Generar vector aleatorio

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

* **String**
    * Algunos componentes del codigo fuente de `string/string_suffix_array.cpp` fué extraido de [ekzhang/library](https://github.com/ekzhang/library) `suffix_array.cpp` ➡️ Por **Eric Zhang**
