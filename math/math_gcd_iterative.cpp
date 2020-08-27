// Euclid's algorithm
template<class T>
T gcd(T a, T b) {
    T tmp = 0;
    while (b){
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
// usage:
//   int ans = gcd<int>(15, 25);