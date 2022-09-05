
const int md = 1e9 + 7;

template<typename T> inline T add(T a, T b, const int& mod) { return (a+b>=mod)? a+b-mod : a+b; }
template<typename T> inline T sub(T a, T b, const int& mod) { return (a-b<0)? a-b+mod : a-b; }
template<typename T> inline T mul(T a, T b, const int& mod) { return (1LL*a*b)%mod; }

template<typename T, typename U> T fastpow(T a, U b, const int& mod) {
    assert(0 <= b);
    T answer = static_cast<T>(1);
    while (b > 0) {
        if (b & 1) answer = mul(answer, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return answer;
}

template<typename T> T inverse(T a, const int& mod) {
    a %= mod;
    if (a < 0) a += mod;
    T b = mod, u = 0, v = 1;
    while (a) {
        T t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += mod;
    return u;
}

template<typename T> T division(T a, T b, const int& mod) { return mul(a, inverse(b, mod), mod); }

// Notes:
// 1) a^(b^(a)) % md
//    is equal to:
//    c++ code:
//    int exponent = fastpow(b, c, md-1);
//    int answer = fastpow(a, exponent, md);