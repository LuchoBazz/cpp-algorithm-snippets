template<class T>
vector<T> primeFactors(T number)  {
    vector<T> factors;
    while (number % 2 == 0) {
        factors.push_back(2);
        number = number / 2;
    }
    for (T i = 3; i*i <= number; i += 2) {
        while (number % i == 0) {
            factors.push_back(i);
            number = number / i; 
        }
    }
    if (number > 2)  {
        factors.push_back(number);
    }
    return factors;
}
// usage:
//   int n = 100;
//   vector<int> factors = primeFactors<int>(n);
//   {2, 2, 5, 5}
//   2*2*5*5 = 2^2 * 5^2 = 100