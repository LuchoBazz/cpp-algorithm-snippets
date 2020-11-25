template<class T>
map<T, int> prime_factors(T number)  {
    map<T, int> factors;
    while (number % 2 == 0) {
        factors[2]++;
        number = number / 2;
    }
    for (T i = 3; i*i <= number; i += 2) {
        while (number % i == 0) {
            factors[i]++;
            number = number / i; 
        }
    }
    if (number > 2)  {
        factors[number]++;
    }
    return factors;
}
// usage:
//   int n = 100;
//   map<int, int> factors = prime_factors<int>(n);
//   { 2: 2, 5: 2}
//   2*2*5*5 = 2^2 * 5^2 = 100