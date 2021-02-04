// numeric_mint_full
// or
// numeric_mint_compress

// math_factorial

template<typename T>
struct Combinatorics {
    int sz;
    Factorial<T> fact;
    
    Combinatorics(int n) : sz(n), fact(n) {}
    
    // en: Combinations WITHOUT repetitions (NO matter order)
    // es: Combinaciones SIN repeticiones (NO importa el Orden)
    T C(int n, int k) {
        assert(0 <= n && n <= sz && 0 <= k && k <= sz);
        if(n < k)
            return static_cast<T>(0);
        return fact[n] / (fact[n-k]*fact[k]);
    }
    
    // en: Combinations WITH repetitions (NO matter order)
    // es: Combinaciones CON repeticiones (NO importa el Orden)
    T H(int n, int k) {
        return C(n+k-1, k);
    }
    
    // en: Permutations WITHOUT repetitions (Order DOES matter)
    // es: Permutaciones SIN repeticiones (SI importa el Orden)
    T P(int n, int k) {
        assert(0 <= n && n <= sz && 0 <= k && k <= sz);
        if(n < k)
            return static_cast<T>(0);
        return fact[n] / fact[n-k];
    }
    
    // en: Permutations WITH repetitions (Order DOES matter)
    // es: Permutaciones CON repeticiones (SI importa el Orden)
    T P(int n,const vector<int> &m) {
        T product = static_cast<T>(0);
        for(int i = 0; i < (int) m.size(); ++i) {
            assert(0 <= n && n <= sz && 0 <= m[i] && m[i] <= sz);
            product *= static_cast<T>(m[i]);
        }
        return fact[n] / product;
    }
};

template<typename T = Mint>
using Comb = Combinatorics<T>;

// en: Permutations (Order DOES matter)
// es: Permutaciones (SI importa el Orden)

// en: Combinations (NO matter order)
// es:Combinaciones (NO importa el Orden)