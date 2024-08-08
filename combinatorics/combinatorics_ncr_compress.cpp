const int64_t md = 1e9 + 7;

int64_t fastpow(int64_t a, int64_t b, const int64_t &mod) {
    assert(0 <= b);
    if (b == 0)
        return 1;
    int64_t half = fastpow(a, b / 2, mod);
    int64_t answer = half * half % mod;
    if (b & 1)
        answer = answer * a % mod;
    return answer;
}

int64_t inv(int64_t a, const int64_t &mod) { return fastpow(a, mod - 2, mod); }

const int MXF = 1e6;

int64_t fact[MXF];

void build_factorial() {
    fact[0] = 1;
    for (int i = 1; i < MXF; ++i) {
        fact[i] = fact[i - 1] * i % md;
    }
}

int64_t nCr(int n, int r) {
    if (n < r)
        return 0;
    return fact[n] * inv(fact[n - r] * fact[r] % md, md) % md;
};

// auto nCr = [&](int n, int r) -> int64_t {
//     if (n < r)
//         return 0;
//     return fact[n] * inv(fact[n - r] * fact[r] % md, md) % md;
// };

// at main()
// build_factorial();
