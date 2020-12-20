// numeric_mint

template <typename T>
struct FactorizerVarMod { static T value; };
template <typename T>
T FactorizerVarMod<T>::value;

// Miller-Rabin primality test
template <typename T>
bool miller_rabin(T number, const vector<T>& bases) {
    if (number < 2) return false;
    vector<T> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (const T& x : small_primes) {
        if (number % x == 0) {
            return number == x;
        }
    }
    if (number < 31 * 31) return true;
    int s = 0;
    T d = number - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    FactorizerVarMod<T>::value = number;
    for (const T& a : bases) {
        if (a % number == 0) continue;
        Modular<FactorizerVarMod<T>> cur = a;
        cur = fastpow(cur, d);
        if (cur == 1) continue;
        bool witness = true;
        for (int r = 0; r < s; r++) {
            if (cur == number - 1) {
                witness = false;
                break;
            }
            cur *= cur;
        }
        if (witness) return false;
    }
    return true;
}

bool miller_rabin(uint64_t number) {
    if (number < 2) return false;
    vector<uint32_t> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (uint32_t x : small_primes) {
        if (number == x) return true;
        if (number % x == 0) return false;
    }
    if (number < 31 * 31) return true;
    uint32_t s = __builtin_ctzll(number - 1);
    uint64_t d = (number - 1) >> s;
    function<bool(uint64_t)> witness = [&number, &s, &d](uint64_t a) {
        uint64_t cur = 1, p = d;
        while (p > 0) {
            if (p & 1) {
                cur = (uint64_t) cur * a % number;
            }
            a = (uint64_t) a * a % number;
            p >>= 1;
        }
        if (cur == 1) return false;
        for (uint32_t r = 0; r < s; r++) {
            if (cur == number - 1) return false;
            cur = (uint64_t) cur * cur % number;
        }
        return true;
    };
    vector<uint64_t> bases_64bit = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (uint64_t a : bases_64bit) {
        if (a % number == 0) return true;
        if (witness(a)) return false;
    }
    return true;
}

template<typename T>
bool is_prime_slow(T number) {
    if(number <= 0) return false;
    else if(number <= 3) return true;
    if(number%2==0 || number%3==0) return false;
    for(T i = 5; i*i <= number; i += 6) {
        if(number%i==0 || number%(i+2)==0) {
            return false;
        }
    }
    return true;
    // Time Complexity: O(sqrt(N)), Space Complexity:  O(1)
}

bool is_prime(int64_t n) {
    return miller_rabin(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

bool is_prime(int32_t n) {
    return miller_rabin(n, {2, 7, 61});
}
