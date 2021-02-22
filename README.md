# :pushpin: Algorithms Template for Competitive Programming

Este repositorio contiene templates de algorimtos y estructuras de datos populares codificados en C++ para usar en competencias de programación.

## Contenido

* **Misc**
    * **Debugging**
        * `to_string_main` - metodo to_string de los principales tipos de datos y estructuras de datos estandard.
        * `to_string_other` - metodo to_string de pairs, tuple y bitset.

    * **Misc**
        * `misc_main` - Macros principales del template.
        * `misc_data_types` - Macros para acortar los tipos de datos numericos.
        * `misc_pairs` - Macros para acortar las tuples y pairs.
        * `misc_precise` - Macros para acortar la precision de decimales.
        * `misc_infinity` - Macros que define las constantes de infinito.
        * `misc_loops` - Macros para acortar los loops.
        * `misc_min_max` - funciones min y max por referencia.
        * `misc_directions` - Array con los valores para explorar una cuadricula 2D.
        * `misc_reference` - Macros para acurtar el codigo de las referencias de un vector y fill un array.
        * `misc_math` - Algunas constantes y funciones matematicas.
        * `misc_vector_n_d` - Funciones para acortar la creacion de un vector de 2,3 y 4 dimensiones.
        * `misc_cond` - Funciones y macros para acortar condiciones.
        * `misc_bits` - Operaciones con Bits.
        * `misc_unique` - Eliminar valores duplicados de un vector.
        * `misc_tree_order_statistic` - Implementacion de un Tree Order Statistic en Set y Map.
        * `misc_y_combinator` - Permite hacer una función Lambda Recursiva.

* **Geometry**
    * `2d_geometry_point` - Objeto Point.
    * `2d_geometry_polygon` - Objeto Polygon.
    * `2d_geometry_area` - Algoritmo que calcula el area de un poligono.
    * `2d_geometry_perimeter` - Algoritmo que calcula el perimetro de un poligono.
    * `2d_geometry_convex_hull_mc` - Algoritmo de Convex Hull (Monotone Chain).

* **Math**
    * `math_check_prime` - Test de Primalidad de un numero.
    * `math_divisors` - Obtener todos los divisores de un numero.
    * `math_gcd_recursive` - Maximo comun divisor (Implementación Recursiva).
    * `math_gcd_iterative` - Maximo comun divisor (Implementación Iterativa).
    * `math_lcm` - Minimo comun multiplo.
    * `math_prime_factors` - Obtener los factores primos de un numero.
    * `math_sieve` - Todos los numeros primos en un rango dado.
    * `math_is_power_of_n` - Algoritmo que verifica si un numero es potencia de `n`.
    * `math_matrix` - Clase que representa a una matrix 2D con sus operaciones matriciales.
    * `math_polynomial` - Clase Polinomio con las siguientes Operaciones (Suma, Resta, Multiplicación, Division y Modulo).
    * `math_diophantine_best` - Funcion Diofandina que cumple la siguiente condicion *|x|, |y| <= max(|a|, |b|, |c|)*.
    * `math_diophantine_std` - Implementacion estandar de la Funcion Diofandina.
    * `math_extgcd_iterative` - Algoritmo Extendido de Euclides (Iterativo).
    * `math_extgcd_recursive` - Algoritmo Extendido de Euclides (Recursivo).
    * `math_fft_iterative` - Algoritmo de la Transformada Rapida de Fourier (Iterativo).
    * `math_fft_recursive` - Algoritmo de la Transformada Rapida de Fourier (Recusiva).
    * `math_factorial` - Implementación del Factorial.

* **Query Range**
    * `range_query_segment_tree` - Estructura de datos Segment Tree.
    * `range_query_sum_immutable` - Consultas de suma en rangos (Immutable).
    * `ange_query_sum_2d_immutable` - Consultas de sumas en rangos 2D (Immnutable).
    * `range_query_fenwick_tree_std` - Arbon binario Indexado estandard (fenwick tree)
    * `range_query_segment_tree_lazy_index_sum_min_max` - Estructura de datos Segment Tree Lazy propagation con (add, max, min, index) operaciones.
    * `range_query_segment_tree_lazy_sum_min_max` - Estructura de datos Segment Tree Lazy propagation con (add, max, min) operaciones.
    * `range_query_segment_tree_lazy_template` - Template de la estructura de datos Segment Tree Lazy propagation.
    * `range_query_sum_lower_bound_segment_tree_lazy` - Algoritmo Lower Bound en el Segment Tree Lazy.
    * `range_query_find_less_than_segment_tree_lazy` - Encontrar el elemento menor mas a la derecha de un valor dado en el Segment Tree Lazy.
    * `range_query_dynamic_segment_tree` - Implementacion de un Segment Tree con nodos Dinamicos.
    * `range_query_persistent_segment_tree` - Implementacion de un Segment Tree Persistente.
    * `range_query_sqrt_decomposition` - Implementacion de SQRT Descomposition usando Bucket
    * 


* **Graph**
    * `graph_graph` - Clase padre de la representacion de un grafo.
    * `graph_digraph` - Clase hijo que representa a un grafo dirigido.
    * `graph_undigraph` - Clase hijo que representa a un grafo no dirigido.
    * `graph_dijkstra_std` - Algoritmo de Dijkstra.
    * `graph_dijkstra_path` - Algoritmo de Dijkstra que permite reconstruir la ruta.
    * `graph_dsu` - Estructura de datos Disjoint Set Union.
    * `graph_toposort_dfs` - Algoritmo de ordenamiento topologico usando dfs.
    * `graph_kruskal` - Algoritmo de Kruskal (Minimo Arbol de Expansión).
    * `graph_scc_kosaraju` - Algoritmo de Kosaraju para buscar los Componentes fuertemente conexos (SCC).
    * `graph_bellman_ford` - Algoritmo estandard de Bellman Ford.
    * `graph_find_cycle` - Encuentra circulos en un Grafo.

* **Data Structure**
    * `data_structure_mos_algorithm` - Implementación del Algoritmo de Mo.
    * `data_structure_trie_automaton` - Implementación del Arbol de Prefijos mediante un Automata.
    * `data_structure_trie_dynamic` - Implementación del Arbol de Prefijos mediante un Nodos Dinamicos.

* **Numeric**
    * `numeric_mint_full` - Template Completo de Aritmetica Modular.
    * `numeric_mint_compress` - Template Completo de Aritmetica Modular Comprimido.
    * `numeric_mod` - Template de Aritmetica Modular Basica.
    * `numeric_bigint` - Template Completo para hacer operaciones numericas con numeros muy grandes.
    * `numeric_fastpow` - Calcula potencias rapidamente. 

* **String**
    * `string_suffix_array` - Algoritmo de Suffix Array.
    * `string_kmp` - Algoritmo Knuth-Morris-Pratt (KMP).
    * `string_lps` - Mas grande prefijo que es tambien sufijo (Longest prefix suffix).
    * `string_trie` - Estructura de datos Arbol de Prefijos Trie (Prefix Tree).
    * `string_manacher` - Algoritmo Manacher (Encontrar todos los substring palindromos de un string en O(n)).
    * `string_split` - Función split en string.
    * `string_hashing` - Implementación de Rolling Hashing 

* **Combinatorics**
    * `combinatorics_combinations_permutations` - Metodos que permiten contar el numero de combinaciones y permutaciones de un conjunto de elementos.

* **Random**
    * `random_init` - Generar valor aleatorio en un rango.
    * `random_permutation` - Generar permutación aleatoria.
    * `random_vector` - Generar vector aleatorio.

* **Searches**
    * `searches_binary_search_I` - Implementacion estandar de busqueda binaria.
    * `searches_binary_search_II` - Segunda Implementación de busqueda binaria.
    * `searches_binary_search_III` - Implementacion de busqueda binaria basada en busqueda exponencial.

* **Techniques**
    * `techniques_divide_and_conquer` - Template de la Técnica Divide y Conquistaras.
    * `techniques_sliding_windows` - Template de la Técnica Ventana Deslizante.
    * `techniques_sweep_line` - Template de la Técnica Linea de Barrido.
    * `techniques_two_pointer1_pointer2` - Template de la Técnica de dos punteros en dos secuencias.
    * `techniques_two_pointer_left_right_boundary` - Template de la Técnica de dos punteros "Limite izquierdo y derecho".
    * `techniques_two_pointers_old_and_new_state` - Template de la Técnica de dos punteros "Estado viejo y nuevo".
    * `techniques_two_pointers_slow_fast` - Template de la Técnica de dos punteros "Puntero lento y rapido".

* **IO - Input/Output**
    * `io_print` - Imprime varias variales con codigo corto.
    * `io_read_write` - Leer datos de (vector, list, forward_list or deque) y los imprime

* **Template**
    * `template_main` - Template con Task para c++17.
    * `template_std` - Template para c++17.
    * `template_test_case` - Fragmento de caso de prueba
    * `template_usaco` - Template para usaco.org
    * `template_spoj` - Template para spoj.com
    * `template_std_leetcode` - Template para leetcode.com

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

    * Algunos componentes del codigo fuente de `string/string_hashing.cpp` fué extraido de [mavd09/notebook_unal](https://github.com/mavd09/notebook_unal) `String/Hashing.cpp` ➡️ Por **Osman Jimenez, Manuel Vergara y Víctor Ramírez**

    * Algunos componentes del codigo fuente de `string/string_hashing_dynamic_compress.cpp` fué extraido de [ekzhang/library](https://github.com/ekzhang/library) `hashing_bit.cpp` ➡️ Por **Eric Zhang**

* **Query Range**
    * Algunos componentes del codigo fuente de este folder fué extraido de [the-tourist/algo](https://github.com/the-tourist/algo) `data > segtree.cpp` ➡️ Por **Gennady Korotkevich (Tourist)**