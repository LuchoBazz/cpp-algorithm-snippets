// numeric_mint_compress
// or
// numeric_mint_full

// math_factorial

template<typename T>
struct Combinatorics {
    int sz;
    Factorial<T> fact;
    
    Combinatorics() : sz(-1), fact() {}
    Combinatorics(int n) : sz(n), fact(n) {}
    
    T C(int n, int k) { // O(1) with preprocessing O(n)
        assert(0 <= n && n <= sz && 0 <= k && k <= sz);
        if(n < k)
            return static_cast<T>(0);
        return fact[n] / (fact[n-k]*fact[k]);
    }

    T C_slow(int n, int k) { // O(k)
        assert(0 <= n && n <= sz && 0 <= k && k <= sz);
        if(n < k)
            return static_cast<T>(0);
        T ans = static_cast<T>(1);
        for(int i = 1; i <= k; i++) {
            ans *= static_cast<T>(n - k + i);
            ans /= static_cast<T>(i);
        }
        return ans;
    }
    
    T H(int n, int k) {
        return C(n+k-1, k);
    }
    
    T P(int n, int k) {
        assert(0 <= n && n <= sz && 0 <= k && k <= sz);
        if(n < k)
            return static_cast<T>(0);
        return fact[n] / fact[n-k];
    }
    
    T P(int n, const vector<int> &m) {
        T product = static_cast<T>(1);
        for(int i = 0; i < (int) m.size(); ++i) {
            assert(0 <= n && n <= sz && 0 <= m[i] && m[i] <= sz);
            product *= fact[m[i]];
        }
        return fact[n] / product;
    }

    T catalan(int n) {
        return C(2*n, n) / static_cast<T>(n+1);
    }
};

template<typename T>
using Comb = Combinatorics<T>;

// en: Permutations (Order DOES matter)
// es: Permutaciones (SI importa el Orden)

// en: Combinations (NO matter order)
// es:Combinaciones (NO importa el Orden)

// ********************************************************************

// C(n, k):
// en: Combinations WITHOUT repetitions (NO matter order)
// es: Combinaciones SIN repeticiones (NO importa el Orden)

// H(n, k):
// en: Combinations WITH repetitions (NO matter order)
// es: Combinaciones CON repeticiones (NO importa el Orden)

// P(n, k):
// en: Permutations WITHOUT repetitions (Order DOES matter)
// es: Permutaciones SIN repeticiones (SI importa el Orden)

// P(n, {m1, m2, m3, ... }):
// en: Permutations WITH repetitions (Order DOES matter)
// es: Permutaciones CON repeticiones (SI importa el Orden)

// catalan(n):
// k-th: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440

// ********************************************************************

// Properties

// C(n, k) = C(n, n-k)
// C(n, 0) = C(n, n) = 1
// C(n, k) = C(n-1, k-1) + C(n-1, k)
// C(n, 0)+C(n, 1)+C(n, 2)+...+C(n, n-1)+C(n, n) = 2^n