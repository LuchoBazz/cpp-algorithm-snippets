#define PI   3.141592653589793238462643383279502884L // acos(-1);
#define E    2.718281828459045235360287471352662497L
#define eps  1e-9

template<typename T>
int cmp(const T &a, const T &b) {
    return ( (a + eps < b)? -1 :( (b + eps < a )? 1 : 0) );
}

template<typename T>
T ceiling_division(T numerator, T denominator) {
    assert(denominator != static_cast<T>(0));
    return (numerator+denominator-1)/denominator;
}

// How much does it need to add to n so that it is divisible by k
template<typename T>
T distance_divisible(T n, T k) {
    assert(0 < k); if(n < k) return k - n % k;
    return n % k;
}