---
sidebar_position: 2
title: Combinatorics
sidebar_label: Combinatorics
---

This document provides an overview of a set of utilities for combinatorics and permutations implemented in C++. The code is designed with modularity and efficiency in mind, suitable for competitive programming scenarios where performance and correctness are paramount.

### 1. Constants and Macros
- **`md`**: A large prime number ($10^9 + 7$), commonly used as the modulus for competitive programming to avoid overflow and ensure results fit within standard data types.
- **`ceil(a, b)`**: A macro to calculate the ceiling of the division of two integers, implemented as $\frac{a + b - 1}{b}$.

### 2. Utility Functions
#### `fastpow`
```cpp
const int64_t md = 1e9 + 7;

int64_t fastpow(int64_t a, int64_t b) {
  if (b == 0)
    return 1;
  int64_t half = fastpow(a, b / 2);
  int64_t result = half * half % md;
  if (b & 1)
    result = result * a % md;
  return result;
}
```
Efficiently computes $a^b \mod \text{md}$ using recursive exponentiation by squaring. This function operates in $O(\log b)$ time, making it suitable for handling large exponents.

#### `inverse`  
```cpp
auto inverse = [&](int64_t num) -> int64_t {
  return fastpow(num, md - 2);
};
```  
Computes the modular inverse of a number $\( \text{num} \mod \text{md} \)$ using Fermat's Little Theorem. This method is efficient and operates in $\( O(\log \text{md}) \)$.  

### 3. Precomputations
#### Factorial Table Construction
```cpp
const int MXN = 2e5 + 10;
int64_t fact[MXN];

void buildFactorial() {
  fact[0] = 1;
  for (int i = 1; i < MXN; ++i) {
    fact[i] = fact[i - 1] * i % md;
  }
}
```
Precomputes factorial values up to a maximum limit (`MXN`) modulo `md`. This precomputation allows for constant-time access to factorial values, which are used extensively in combinatorics calculations.


### 4. Combinatorics

#### Binomial Coefficients (`nCk`)
```cpp
auto nCk = [&](int n, int k) -> int64_t {
  return fact[n] * inverse(fact[k] * fact[n - k] % md) % md;
};
```
Calculates the binomial coefficient $\binom{n}{k} \mod \text{md}$, representing the number of ways to choose $k$ elements from $n$ elements without repetition. Utilizes modular arithmetic and the precomputed factorials for efficiency.

#### Combinations with Repetition

```cpp
auto combinationsWithRepetition = [&](int n, int k) -> int64_t {
  return nCk(n + k - 1, k);
};
```
Computes combinations with repetition using the formula $\binom{n+k-1}{k}$. This is useful in problems involving the selection of $k$ items from $n$ types with replacement.

### 5. Permutations
#### Permutations without Repetition
```cpp
auto permutations = [&](int n, int k) -> int64_t {
  if (k > n) return 0;
  return fact[n] * inverse(fact[n - k]) % md;
};
```
Calculates the number of ways to arrange $k$ items selected from $n$ items without repetition. Returns $0$ if $k > n$.

#### Permutations with Repetition
```cpp
auto permutationsWithRepetitions = [&](int n, const vector<int>& m) -> int64_t {
  int64_t product = 1;
  for (int mi : m) {
    assert(0 <= mi);
    product = product * fact[mi] % md;
  }
  return fact[n] * inverse(product) % md;
};
```
Determines the number of distinct permutations of $n$ items where some items are repeated. The vector `m` specifies the frequencies of each distinct item.

### 6. Usage Instructions
1. **Precompute Factorials**: Call `buildFactorial()` at the start of the program to initialize the factorial values.
2. **Binomial Coefficients**:
```cpp
int64_t options = nCk(N, K);
```
Use this for problems involving combinations.
3. **Combinations with Repetition**:
```cpp
int64_t result = combinationsWithRepetition(n, k);
```
Useful for problems where repetition is allowed.
4. **Permutations**:
- Without repetition:
```cpp
int64_t perm = permutations(n, k);
```
- With repetition:
```cpp
vector<int> frequencies = {freq1, freq2, ...};
int64_t perm = permutationsWithRepetitions(n, frequencies);
```

### Summary
This set of utilities provides a robust framework for handling common combinatorics and permutations problems in competitive programming. The modular and efficient design ensures quick computations, leveraging precomputed factorials and modular arithmetic to handle large inputs effectively.


### References
- [Source Code Implementation](https://gist.github.com/LuchoBazz/434d918498e61007bba9767bf6469a90)

