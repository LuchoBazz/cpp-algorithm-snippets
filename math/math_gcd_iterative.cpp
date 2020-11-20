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
// Euclid's algorithm
// usage:
//   int ans = gcd(15, 25);