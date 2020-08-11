const int MOD = int(1e9+7);

template<typename T>
T sub(T a, T b) {
    return ((a-b)%MOD + MOD) % MOD;
}

template<typename T>
T add(T a, T b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}

template<typename T>
T mul(T a, T b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

template<typename T>
T power(T a, T b) {
    T answer = (T)1;
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
        int t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}

T divi(T a, T b) {
    return mul(a ,  inverse(b));
}