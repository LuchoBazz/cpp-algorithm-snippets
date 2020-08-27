template<class T>
T lcm(T a, T b) {  
    return (a*b)/gcd<T>(a, b);  
}
// usage:
//   int ans = gcd<int>(15, 25);
//   int ans = lcm<int>(15, 25);