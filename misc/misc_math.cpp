#define PI   3.141592653589793238462643383279502884L // acos(-1);
#define E    2.718281828459045235360287471352662497L
#define eps  1e-9

template<typename T>
int cmp(const T &a, const T &b) {
    return ( (a + eps < b)? -1 :( (b + eps < a )? 1 : 0) );
}

// ceiling division
template<typename T>
T ceil(T numerator, T denominator) {
    assert(denominator != static_cast<T>(0));
    return (numerator+denominator-1)/denominator;
}

// #define ceil(a, b) (((a) + (b) - 1) / (b)) 

// distance_divisible:
// How much does it need to add to n so that it is divisible by k
template<typename T>
T distance(T n, T k) {
    assert(0 < k); if(n < k) return k - n % k;
    return n % k;
}

// Tested in: https://atcoder.jp/contests/abc048/tasks/abc048_b
// Among the integers between 0 and num, inclusive
// how many are divisible by div?
template<typename T> T divs_cnt(T num, T div) {
  return num < 0 ? 0 : num / div + 1;
}

// Among the integers between a and b, inclusive
// how many are divisible by div?
template<typename T> T divs_cnt_range(T a, T b, T div) {
  return divs_cnt(b, div) - divs_cnt(a - 1, div);
}
