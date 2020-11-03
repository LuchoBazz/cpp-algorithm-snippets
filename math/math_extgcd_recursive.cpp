template<typename T>
tuple<T, T, T> extgcd(T a, T b) {
    if (a == 0) {
        return {b, 0, 1};
    }
    T p = b / a;
    auto [g, y, x] = extgcd(b - p * a, a);
    x -= p * y;
    return {g, x, y};
}
// Usage:
//   auto [g, x, y] = extgcd(a, b);

// a*x ≡ 1 (mod m) -> If and only if gcd(a, m) == 1
// a*x + m*y = 1

// auto [g, x, y] = extgcd(a, m);

// a*x + b*y = gcd(a, b) 