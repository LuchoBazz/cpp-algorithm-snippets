template<typename T, typename U>
T fastpow(T a, U b) {
    assert(b >= 0);
    T ans = (T)1;
    while (b > 0) {
        if (b & 1) {
            ans = ans*a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}