const int MOD = int(1e9+7);

template<typename T>
T sub(T a, T b) {
    return (1LL*(a-b)%MOD + MOD) % MOD;
}

template<typename T>
T add(T a, T b) {
    return (1LL*(a%MOD) + 1LL*(b%MOD)) % MOD;
}

template<typename T>
T mul(T a, T b) {
    return (1LL*(a%MOD) * (b%MOD)) % MOD;
}

template<typename T, typename U>
T fastpow(T a, U b) {
    assert(0 <= b);
    T answer = static_cast<T>(1);
    while (b > 0) {
        if (b & 1) {
            answer = mul(answer, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return answer;
}

template<typename T>
T inverse(T a) {
    a %= MOD;
    if (a < 0) a += MOD;
    T b = MOD, u = 0, v = 1;
    while (a) {
        T t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}

template<typename T>
T division(T a, T b) {
    return mul(a, inverse(b));
}