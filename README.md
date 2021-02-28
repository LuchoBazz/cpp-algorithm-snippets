# :pushpin: Algorithms Template for Competitive Programming

This repository contains templates of useful algorithms and data structures coded in C++ for use in competitive programming.

## Contents

* **Misc**
    * **Debugging**
        * `to_string_main` - *to_string* method of the main data types and standard data structures.
        * `to_string_other` - *to_string* method of pairs, tuple and bitset.

    * **Misc**
        * `misc_main` - Main macros of the template.
        * `misc_data_types` - Macros to shorten the writing of numeric data types.
        * `misc_pairs` - Macros to shorten the writing of tuples and pairs.
        * `misc_precise` - Macros for Sets the decimal precision to be used to format floating-point values on output operations.
        * `misc_infinity` - Macros defining the constants of infinity.
        * `misc_loops` - Macros to shorten loop writing.
        * `misc_min_max` - *min* and *max* functions by reference.
        * `misc_directions` - Array with the values to explore a 2D grid.
        * `misc_reference` - Macros to shorten the code writing of vector references.
        * `misc_math` - Some mathematical constants and functions.
        * `misc_vector_n_d` - Functions to shorten the writing of code in the creation of a vector of 2, 3 and 4 dimensions.
        * `misc_cond` - Functions and macros to shorten the code writing of some defined conditions..
        * `misc_bits` - Operations and tricks with Bits.
        * `misc_unique` - Remove duplicate values from a vector.
        * `misc_tree_order_statistic` - Implementation of a Tree Order Statistic in Set and Map.
        * `misc_y_combinator` - Allows you to define a recursive Lambda function.

* **Geometry**
    * `2d_geometry_point` - Class Point.
    * `2d_geometry_polygon` - Class Polygon.
    * `2d_geometry_area` - Algorithm that calculates the area of a polygon.
    * `2d_geometry_perimeter` - Algorithm that calculates the perimeter of a polygon.
    * `2d_geometry_convex_hull_mc` - Convex Hull (Monotone Chain) algorithm.

* **Math**
    * `math_check_prime` - Primality test of a number.
    * `math_divisors` - Function for get all the divisors of a number.
    * `math_gcd_recursive` - Greatest common divisor (Recursive Implementation).
    * `math_gcd_iterative` - Greatest common divisor (Iterative Implementation).
    * `math_lcm` - Least common multiple.
    * `math_prime_factors` - function that calculates the prime factors of a number.
    * `math_sieve` - function to get all prime numbers in a given range.
    * `math_is_power_of_n` - Algorithm that checks if a number is a power of `n`.
    * `math_matrix` - Class that represents a 2D matrix with its matrix operations.
    * `math_polynomial` - Polynomial class with the following Operations (Addition, Subtraction, Multiplication, Division and Modulo).
    * `math_diophantine_best` - Diofandina function that meets the following condition *|x|, |y| <= max(|a|, |b|, |c|)*.
    * `math_diophantine_std` - Standard implementation of the Diofandina Function.
    * `math_extgcd_iterative` - Euclid's Extended Algorithm (Iterative).
    * `math_extgcd_recursive` - Euclid's Extended Algorithm (Recursive).
    * `math_fft_iterative` - Fast Fourier Transform Algorithm (Iterative).
    * `math_fft_recursive` - Fast Fourier Transform Algorithm (Recursive).
    * `math_factorial` - Factorial implementation.

* **Query Range**
    * `range_query_segment_tree` - Segment Tree data structure.
    * `range_query_sum_immutable` - Query of sum in ranges (Immutable).
    * `ange_query_sum_2d_immutable` - Queries of sums in 2D ranges (Immutable).
    * `range_query_fenwick_tree_std` - Standard Indexed Binary Tree (fenwick tree).
    * `range_query_segment_tree_lazy_compress` - Segment Tree Lazy propagation data structure with compressed (add, max, min, index) operations.
    * `range_query_segment_tree_lazy_full` - Segment Tree Lazy propagation data structure with (add, max, min, index) operations complete includes *find_first* and *find_last* methods.
    * `range_query_segment_tree_lazy_template` - Template of the Segment Tree Lazy propagation data structure.
    * `range_query_sum_lower_bound_segment_tree_lazy` - Lower Bound algorithm in the Segment Tree Lazy.
    * `range_query_find_less_than_segment_tree_lazy` - Find the rightmost minor element of a given value in the Segment Tree Lazy.
    * `range_query_dynamic_segment_tree` - Implementation of a Segment Tree with Dynamic nodes.
    * `range_query_persistent_segment_tree` - Implementation of a Persistent Segment Tree.
    * `range_query_sqrt_decomposition` - SQRT Decomposition implementation using Bucket.

* **Graph**
    * `graph_graph` - Parent class of the representation of a graph.
    * `graph_digraph` - Child class representing a directed graph.
    * `graph_undigraph` - Child class representing an undirected graph.
    * `graph_dijkstra_std` - Implementation of the Dijkstra Algorithm.
    * `graph_dijkstra_path` - Dijkstra algorithm that allows to reconstruct the route.
    * `graph_dsu` - Disjoint Set Union data structure.
    * `graph_toposort_dfs` - Topological sorting algorithm using dfs.
    * `graph_kruskal` - Kruskal's algorithm (Minimum Spanning Tree).
    * `graph_scc_kosaraju` - Kosaraju algorithm to search for Strongly Connected Components (SCC).
    * `graph_bellman_ford` - Bellman Ford standard algorithm.
    * `graph_find_cycle` - Find circles in a Graph.

* **Data Structure**
    * `data_structure_mos_algorithm` - implementation of Mo's Algorithm.
    * `data_structure_trie_automaton` - Implementation of the Prefix Tree through an Automata.
    * `data_structure_trie_dynamic` - Implementation of the Prefix Tree through a Dynamic Node.

* **Numeric**
    * `numeric_mint_full` - Modular arithmetic template.
    * `numeric_mint_compress` - Compressed Modular Arithmetic Template.
    * `numeric_mod` - Basic Modular Arithmetic Template.
    * `numeric_bigint` - Complete Template to do numerical operations with very large numbers.
    * `numeric_fastpow` - Fast Exponentiation.

* **String**
    * `string_suffix_array` - Suffix Array algorithm.
    * `string_kmp` - Knuth-Morris-Pratt (KMP) algorithm.
    * `string_lps` - Longest prefix which is also suffix.
    * `string_manacher` - Manacher algorithm (Find all palindrome substring of a string in O(n)).
    * `string_split` - Split function in string.

* **Combinatorics**
    * `combinatorics_combinations_permutations` - Methods that allow counting the number of combinations and permutations of a set of elements.
    * `combinatorics_next_combination` - Method that generates all the combinations of a set of `n` elements with subsets of` k` elements.
    * `combinatorics_all_combinations_backtracking` - Method that generates all the combinations of a set of `n` elements with subsets of` k` elements using backtracking.

* **Random**
    * `random_init` - Generate random value in a range.
    * `random_permutation` - Generate random permutation.
    * `random_vector` - Generate a random vector.

* **Searches**
    * `searches_binary_search_I` - Standard binary search implementation.
    * `searches_binary_search_II` - Second Implementation of binary search.
    * `searches_binary_search_III` - Implementation of binary search based on Binary Jumping.

* **Techniques**
    * `techniques_divide_and_conquer` - Template of the Divide and Conquer Technique.
    * `techniques_sliding_windows` - Sliding Window Technique Template.
    * `techniques_sweep_line` - Template of the Sweep Line Technique.
    * `techniques_two_pointer1_pointer2` - Template of the Two Pointers Technique in two sequences.
    * `techniques_two_pointer_left_right_boundary` - Template of the Two Pointer Technique "Left and Right Boundary".
    * `techniques_two_pointers_old_and_new_state` - Template of the Two Pointer Technique "Old and New State".
    * `techniques_two_pointers_slow_fast` - Template of the technique of two pointers "Slow and fast pointer".

* **IO - Input/Output**
    * `io_print` - Print multiple variables with short code writing.
    * `io_read_write` - Read data from (vector, list, forward_list or deque) and print it.

* **Template**
    * `template_main` - Template with Task for c++17.
    * `template_std` - Template for c++17.
    * `template_test_case` - Test case snippet.
    * `template_usaco` - Template for usaco.org
    * `template_spoj` - Template for spoj.com
    * `template_std_leetcode` - Template for leetcode.com
    * `template_random` - Template to generate random test cases.

## Creditos
 
* **Debugging**
    * Some components of the source code of this folder were taken from [the-tourist/algo](https://github.com/the-tourist/algo) `misc > debug.cpp` ➡️ By **Gennady Korotkevich (Tourist)**

* **Graph**
    * Some components of the source code of `graph/graph_digraph.cpp`, `graph/graph_graph.cpp` and `graph/undigraph.cpp` were taken from [the-tourist/algo](https://github.com/the-tourist/algo) `graph > ...` ➡️ By **Gennady Korotkevich (Tourist)**

* **Numeric**
    * Some components of the source code of `numeric/numeric_mint.cpp` were taken from [the-tourist/algo](https://github.com/the-tourist/algo) `numeric > mint.cpp` ➡️ By **Gennady Korotkevich (Tourist)**

    * Some components of the source code of `numeric/bitint.cpp` were taken from [indy256/codelibrary](https://github.com/indy256/codelibrary) `numeric > bitint.cpp` ➡️ By **Andrei Navumenka**

* **String**
    * Some components of the source code of `string/string_suffix_array.cpp` were taken from [ekzhang/library](https://github.com/ekzhang/library) `suffix_array.cpp` ➡️ By **Eric Zhang**

    * Some components of the source code of `string/string_hashing.cpp` were taken from [mavd09/notebook_unal](https://github.com/mavd09/notebook_unal) `String/Hashing.cpp` ➡️ By **Osman Jimenez, Manuel Vergara and Víctor Ramírez**

    * Some components of the source code of `string/string_hashing_dynamic_compress.cpp` were taken from [ekzhang/library](https://github.com/ekzhang/library) `hashing_bit.cpp` ➡️ By **Eric Zhang**

* **Query Range**
    * Some components of the source code of this folder were taken from [the-tourist/algo](https://github.com/the-tourist/algo) `data > segtree.cpp` ➡️ By **Gennady Korotkevich (Tourist)**

* **Combinatorics**
    * Some components of the source code of this folder were taken from [indy256/codelibrary](https://github.com/indy256/codelibrary/) `cpp > combinatorics > enumerating_combinations.cpp` ➡️ By **Andrei Navumenka (indy256)**