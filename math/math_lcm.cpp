// math_gcd_iterative
// or
// math_gcd_recursive

template <class T>
T lcm(T a, T b) {
    return a / gcd<T>(a, b) * b;
}
// usage:
//   int ans = lcm(15, 25);