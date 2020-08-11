const int MOD = int(1e9+7);

template<typename T>
T sub(T a, T b, T mod) {
    return ((a-b)%mod + mod) % mod;
}

template<typename T>
T add(T a, T b, T mod) {
    return ((a%mod) + (b%mod)) % mod;
}

template<typename T>
T mul(T a, T b, T mod) {
    return ((a%mod) * (b%mod)) % mod;
}

template<typename T>
T power(T a, T b, T mod) {
    T answer = (T)1;
    while (b > 0) {
        if (b & 1) {
            answer = mul(answer, a, mod);
        }
        a = mul(a, a, mod);
        b >>= 1;
    }
    return answer;
}

template<typename T>
T inverse(T a, T mod) {
    a %= mod;
    if (a < 0) a += mod;
    T b = mod, u = 0, v = 1;
    while (a) {
        int t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += mod;
    return u;
}


template<typename T>
T div(T a, T b, T mod) {
    return mul(a ,  inverse(b, mod), mod);
}