// usage:
//   int ans = gcd<int>(15, 25);
///  int ans = lcm<int>(15, 25);

// Euclid's algorithm
template<class T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

template<class T>
T lcm(T a, T b) {  
    return (a*b)/gcd<T>(a, b);  
}