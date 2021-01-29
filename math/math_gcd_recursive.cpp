template<class T>
T gcd(T a, T b) {
    return (b == 0)?a:gcd(b, a % b);
}
// Euclid's algorithm
// usage:
//   int ans = gcd<int>(15, 25);