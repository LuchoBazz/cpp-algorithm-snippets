# :pushpin: Algorithms Template for Competitive Programming

This repository contains templates of useful algorithms and data structures coded in C++ for use in competitive programming.

## Quick Start

### Automatic Snippet Generation

This repository includes scripts to automatically generate code snippets for your editor:

#### For VS Code
```bash
python3 generate_vscode_snippets.py
```

This script automatically:
- Scans all `.cpp` files in the subdirectories
- Generates VS Code snippets in `cpp.json`
- Places them in your VS Code user snippets directory:
  - **Windows**: `%APPDATA%\Code\User\snippets\cpp.json`
  - **Linux**: `~/.config/Code/User/snippets/cpp.json`
  - **macOS**: `~/Library/Application Support/Code/User/snippets/cpp.json`
- Replaces Vim date placeholders with VS Code variables for template files

#### For Vim/Neovim (UltiSnips)
```bash
bash generate_snippets.sh
```

This script:
- Searches for all `.cpp` files recursively
- Generates UltiSnips format snippets
- Outputs to `~/.vim/UltiSnips/cpp/cpp_generate.snippets`
- Each snippet is prefixed with the filename (without extension)

After running the appropriate script, you can use any algorithm by typing its prefix (e.g., `graph_dijkstra_std`) and triggering your editor's autocomplete.

## Contents

`Command` - Description

* **Misc**
    * **Debugging**
        * `misc_debug` - Comprehensive debugging utilities with *to_string* methods for main data types, standard data structures, pairs, tuples, and bitsets.

    * **Misc**
        * `misc_pragma` - Compiler optimization pragmas for competitive programming.
        * `misc_data_types` - Macros to shorten the writing of numeric data types.
        * `misc_pairs` - Macros to shorten the writing of tuples and pairs.
        * `misc_precise` - Macros for setting decimal precision to format floating-point values on output operations.
        * `misc_infinity` - Macros defining the constants of infinity.
        * `misc_loops` - Macros to shorten loop writing.
        * `misc_min_max` - *min* and *max* functions by reference.
        * `misc_directions` - Array with the values to explore a 2D grid.
        * `misc_references` - Macros to shorten the code writing of vector references.
        * `misc_math` - Mathematical constants and utility functions.
        * `misc_vector_n_d` - Functions to create vectors of 2, 3 and 4 dimensions with shortened syntax.
        * `misc_cond` - Functions and macros to simplify conditional code writing.
        * `misc_bits` - Bit manipulation operations and tricks.
        * `misc_unique` - Remove duplicate values from a vector.
        * `misc_y_combinator` - Y Combinator pattern to define recursive lambda functions.
        * `misc_argsort` - Returns indices that would sort an array.
        * `misc_coordinate_compression` - Compress coordinates to a smaller range while preserving relative order.
        * `misc_date` - Date handling utilities and formatters.
        * `misc_format_problem_answer` - Utilities to format problem outputs consistently.
        * `misc_integer128` - 128-bit integer support and operations.
        * `misc_to_reverse` - Utilities to reverse sequences and containers.
        * `misc_unreachable` - Macro to mark unreachable code paths for optimization.

* **Geometry**
    * `2d_geometry_point` - Point representation in 2D space with basic operations (distance, dot product, cross product).
    * `2d_geometry_polygon` - Polygon data structure for managing collections of points.
    * `2d_geometry_area` - Computes the area of a polygon using the shoelace formula.
    * `2d_geometry_perimeter` - Calculates the total perimeter length of a polygon.
    * `2d_geometry_convex_hull_mc` - Finds the convex hull using the Monotone Chain algorithm (Andrew's algorithm).

* **Math**
    * `math_primality_test` - Primality test of a number.
    * `math_divisors` - Function to get all the divisors of a number.
    * `math_gcd_recursive` - Greatest common divisor (Recursive Implementation).
    * `math_gcd_iterative` - Greatest common divisor (Iterative Implementation).
    * `math_lcm` - Least common multiple.
    * `math_prime_factors_vector` - Function that calculates the prime factors of a number (returns vector).
    * `math_prime_factors_map` - Function that calculates the prime factors of a number with their frequencies (returns map).
    * `math_sieve` - Function to get all prime numbers in a given range using Sieve of Eratosthenes.
    * `math_sieve_full` - Complete implementation of Sieve of Eratosthenes with additional utilities.
    * `math_is_power_of_n` - Algorithm that checks if a number is a power of `n`.
    * `math_matrix` - Class that represents a 2D matrix with its matrix operations.
    * `math_matrix_full` - Complete matrix class with extended operations and utilities.
    * `math_polynomial` - Polynomial class with operations (Addition, Subtraction, Multiplication, Division and Modulo).
    * `math_diophantine_best` - Diophantine equation solver that meets the condition *|x|, |y| <= max(|a|, |b|, |c|)*.
    * `math_diophantine_std` - Standard implementation of the Diophantine equation solver.
    * `math_extgcd_iterative` - Extended Euclidean Algorithm (Iterative).
    * `math_extgcd_recursive` - Extended Euclidean Algorithm (Recursive).
    * `math_fft_recursive` - Fast Fourier Transform Algorithm (Recursive).
    * `math_factorial` - Factorial implementation.
    * `math_phi_euler_sqrt_n` - Euler's totient function calculation in O(√n).
    * `math_mex` - Minimal excludant (MEX) - finds the smallest non-negative integer not in a set.
    * `math_harmonic_lemma_trick` - Harmonic lemma optimization trick for divisor-based problems.

* **Query Range**
    * `range_query_segment_tree` - Segment Tree data structure for efficient range queries and updates.
    * `range_query_sum_immutable` - Query sum in ranges with immutable array (Prefix Sum).
    * `range_query_sum_2d_immutable` - Query sum in 2D ranges with immutable matrix (2D Prefix Sum).
    * `range_query_fenwick_tree_std` - Standard Binary Indexed Tree (Fenwick Tree) for range sum queries and point updates.
    * `range_query_segment_tree_lazy_compress` - Segment Tree with lazy propagation - compressed implementation with (add, max, min, index) operations.
    * `range_query_segment_tree_lazy_full` - Segment Tree with lazy propagation - complete implementation including (add, max, min, index) operations, *find_first* and *find_last* methods.
    * `range_query_segment_tree_lazy_template` - Generic template for Segment Tree with lazy propagation.
    * `range_query_sum_lower_bound_segment_tree_lazy` - Lower bound algorithm on Segment Tree with lazy propagation.
    * `range_query_less_than_segment_tree_lazy` - Find the rightmost element less than a given value in Segment Tree with lazy propagation.
    * `range_query_dynamic_segment_tree` - Segment Tree with dynamic node allocation for sparse data.
    * `range_query_persistent_segment_tree` - Persistent Segment Tree implementation for maintaining query history.
    * `range_query_sqrt_decomposition` - Square Root Decomposition implementation using bucket technique.
    * `range_query_sparse_table_std` - Sparse Table for static range minimum/maximum queries in O(1).

* **Graph**
    * **Graph Structures**
        * `graph_graph` - Parent class of the representation of a graph.
        * `graph_digraph` - Child class representing a directed graph.
        * `graph_undigraph` - Child class representing an undirected graph.
    
    * **Shortest Path Algorithms**
        * `graph_dijkstra_std` - Implementation of Dijkstra's Algorithm for single-source shortest paths in weighted graphs.
        * `graph_dijkstra_path` - Dijkstra algorithm that allows path reconstruction.
        * `graph_bellman_ford` - Bellman-Ford algorithm for single-source shortest paths with negative weights detection.
        * `graph_floyd_warshall` - Floyd-Warshall algorithm for all-pairs shortest paths.
    
    * **Minimum Spanning Tree**
        * `graph_kruskal` - Kruskal's algorithm for finding Minimum Spanning Tree (MST).
    
    * **Graph Connectivity**
        * `graph_dsu` - Disjoint Set Union (Union-Find) data structure for connected components.
        * `graph_scc_kosaraju` - Kosaraju's algorithm to find Strongly Connected Components (SCC).
    
    * **Graph Traversal & Ordering**
        * `graph_toposort_dfs` - Topological sorting algorithm using depth-first search.
        * `graph_find_cycle` - Detect cycles in a graph.
    
    * **Tree Algorithms**
        * `tree_diameter` - Find the diameter (longest path) of a tree.
        * `tree_binary_lifting_std` - Binary lifting technique for LCA (Lowest Common Ancestor) queries.
        * `tree_euler_tour` - Euler tour technique for tree queries.
        * `tree_subtree_queries` - Handle subtree queries efficiently.
        * `tree_distance_i` - Calculate distances in trees.
        * `tree_difference_array_technique_on_trees` - Difference array technique adapted for trees.
        * `tree_merge_trick_on_trees` - Small-to-large merging optimization for tree problems.
        * `graph_centroid_decomposition` - Centroid decomposition technique for divide-and-conquer on trees.

* **Data Structure**
    * `data_structure_mos_algorithm` - Mo's Algorithm for efficient offline range query processing.
    * `data_structure_trie_automaton` - Prefix Tree (Trie) implementation using automaton-based approach.
    * `data_structure_trie_dynamic` - Prefix Tree (Trie) implementation with dynamic node allocation.
    * `data_structure_tree_order_statistic` - Order statistic tree implementation for Set and Map with rank queries.
    * `data_structure_median` - Data structure for efficient median tracking in dynamic datasets.
    * `data_structure_minmax_heap_map` - Min-Max heap implementation using map for dual-ended priority operations.
    * `data_structure_minmax_heap_multiset` - Min-Max heap implementation using multiset for handling duplicates.
    * `data_structure_queue_min_max` - Queue with O(1) minimum and maximum query operations.
    * `data_structure_stack_min_max` - Stack with O(1) minimum and maximum query operations.

* **Numeric**
    * `numeric_mint_full` - Complete modular arithmetic template with full operations support.
    * `numeric_mint_medium` - Medium-sized modular arithmetic template with balanced functionality.
    * `numeric_mint_compress` - Compressed modular arithmetic template with minimal overhead.
    * `numeric_mod` - Basic modular arithmetic operations and utilities.
    * `numeric_mod_fast` - Optimized fast modular arithmetic implementation.
    * `numeric_bigint` - Big integer template for arbitrary precision arithmetic operations.
    * `numeric_fastpow` - Fast exponentiation algorithm (binary exponentiation) for efficient power computation.

* **String**
    * **Suffix Structures**
        * `string_suffix_array` - Suffix Array construction algorithm for efficient substring operations.
    
    * **Pattern Matching**
        * `string_kmp_std` - Knuth-Morris-Pratt (KMP) algorithm for efficient pattern matching.
        * `string_prefix_function` - Prefix function (Longest prefix which is also suffix) used in KMP.
        * `string_rabin_karp_std` - Rabin-Karp algorithm for pattern matching using rolling hash.
        * `string_aho_corasick_counter` - Aho-Corasick algorithm for counting multiple pattern occurrences.
        * `string_aho_corasick_occurrences` - Aho-Corasick algorithm for finding all pattern occurrences in text.
    
    * **Hashing**
        * `string_hashing_static_compress` - Compressed string hashing implementation for static strings.
        * `string_hashing_dynamic_compress` - Compressed string hashing with dynamic updates support.
    
    * **Palindrome & Special Algorithms**
        * `string_manacher` - Manacher's algorithm to find all palindromic substrings in O(n).
        * `string_minimum_expression` - Find the lexicographically minimum rotation of a string.
    
    * **Z-Algorithm**
        * `string_z_algorithm_std` - Standard Z-algorithm for pattern matching and string analysis.
        * `string_z_algorithm_compress` - Compressed implementation of Z-algorithm.
    
    * **Utilities**
        * `string_split` - String splitting utility function.

* **Combinatorics**
    * `combinatorics_combinations_permutations` - Methods to count the number of combinations and permutations of a set of elements.
    * `combinatorics_next_combination` - Generate all combinations of `k` elements from a set of `n` elements (lexicographic order).
    * `combinatorics_all_combinations_backtracking` - Generate all combinations of `k` elements from a set of `n` elements using backtracking approach.
    * `combinatorics_k_th_permutation` - Find the k-th permutation in lexicographic order without generating all permutations.
    * `combinatorics_ncr_compress` - Compressed implementation for computing binomial coefficients (nCr) with modular arithmetic.

* **Random**
    * `random_init` - Initialize random number generator with seed.
    * `random_permutation` - Generate random permutation of integers.
    * `random_vector` - Generate a random vector with specified size and value range.

* **Searches**
    * **Binary Search**
        * `searches_binary_search_I` - Standard iterative binary search implementation for finding an element in a sorted array.
        * `searches_binary_search_II` - Alternative binary search implementation using different boundary handling.
        * `searches_binary_search_III` - Binary search implementation based on Binary Jumping technique for efficient searching.
    * **Binary Search on Real Values**
        * `searches_binary_search_on_real_values_I` - Binary search adapted for continuous/floating-point value ranges.
        * `searches_binary_search_on_real_values_II` - Second implementation of binary search for real numbers with precision handling.
        * `searches_binary_search_on_real_values_III` - Binary search on real values using Binary Jumping approach.
    * **Ternary Search**
        * `searches_ternary_search_on_integers_I` - Ternary search implementation for finding extremum (minimum/maximum) in unimodal integer sequences.
        * `searches_ternary_search_on_real_values_I` - Ternary search for finding extremum in continuous unimodal functions.
        * `searches_ternary_search_on_real_values_II` - Alternative ternary search implementation for real-valued unimodal functions with improved precision.

* **Techniques**
    * **Divide and Conquer**
        * `techniques_divide_and_conquer` - Divide and Conquer technique template for solving problems by breaking them into smaller subproblems.
    
    * **Sliding Window**
        * `techniques_sliding_windows` - Sliding Window technique for efficient processing of contiguous subarrays or substrings.
    
    * **Sweep Line**
        * `techniques_sweep_line` - Sweep Line algorithm template for solving geometric and interval-based problems.
    
    * **Two Pointers**
        * `techniques_two_pointer1_pointer2` - Two Pointers technique for processing two sequences simultaneously.
        * `techniques_two_pointer_left_right_boundary` - Two Pointers technique using left and right boundary approach for array manipulation.
        * `techniques_two_pointers_old_and_new_state` - Two Pointers technique for tracking old and new state transitions.
        * `techniques_two_pointers_slow_fast` - Slow and Fast Pointer technique (Floyd's Algorithm) for cycle detection and linked list problems.

* **Input/Output**
    * `io_print` - Print utility for multiple variables with simplified syntax and automatic formatting.
    * `io_read_write` - Read and write utilities for standard containers (vector, list, forward_list, deque) with streamlined I/O operations.

* **Template**
    * `template_header` - Header template with common includes and configurations for C++17.
    * `template_std` - Standard template for competitive programming in C++17.
    * `template_cases` - Template for handling multiple test cases with automatic case numbering.
    * `template_test_case` - Test case snippet for quick testing and validation.
    * `template_google` - Template optimized for Google Code Jam and Kick Start competitions.
    * `template_usaco` - Template for USACO (USA Computing Olympiad) with file I/O support.
    * `template_std_leetcode` - Template adapted for LeetCode problems with class-based structure.
    * `template_random` - Template for generating random test cases and stress testing.

## Credits
 
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
    * Some components of the source code of this folder were taken from [the-tourist/algo](https://github.com/the-tourist/algo) `data > segtree.cpp` and `sparsetable.cpp` ➡️ By **Gennady Korotkevich (Tourist)**

* **Combinatorics**
    * Some components of the source code of this folder were taken from [indy256/codelibrary](https://github.com/indy256/codelibrary/) `cpp > combinatorics > enumerating_combinations.cpp` ➡️ By **Andrei Navumenka (indy256)**