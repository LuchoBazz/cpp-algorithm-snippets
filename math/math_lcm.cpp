// math_gcd_iterative
// or
// math_gcd_recursive

template<class T>
T lcm(T a, T b) {  
    return (a*b)/gcd<T>(a, b);  
}
// usage:
//   int ans = lcm(15, 25);