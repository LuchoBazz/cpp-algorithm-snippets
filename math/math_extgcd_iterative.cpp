template<typename T>
tuple<T, T, T> extgcd(T a, T b) {
    if(b == T(0)) return {a, 1, 0};
    T x=1, xtmp=0, y=0, ytmp=1;
    while(b != 0) {
        T q = a / b;
        T r = a - b * q;
        T u = x - q * xtmp;
        T v = y - q * ytmp;
        a = b;
        b = r;
        x = xtmp;
        xtmp = u;
        y = ytmp;
        ytmp = v;
    }
    return {a, x, y};
}
// Usage:
//   auto [g, x, y] = extgcd(a, b);

// a*x ≡ 1 (mod m) -> If and only if gcd(a, m) == 1
// a*x + m*y = 1

// auto [g, x, y] = extgcd(a, m);

// a*x + b*y = gcd(a, b) 