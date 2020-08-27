// Euclid's algorithm
template<class T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
// usage:
//   int ans = gcd<int>(15, 25);