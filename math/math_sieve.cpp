template<class T>
vector<T> sieve(T number) {
    vector<bool> is_prime(number+1, false);
    for(T i = 4; i <= number; i += 2) {
        is_prime[i] = true;
    }
    for(T prime = 3; prime <= number; prime += 2) {
        if(!is_prime[prime]) {
            for(int j = prime*2; j <= number; j += prime) {
                is_prime[j] = true;
            }
        }
    }
    vector<T> primes;
    for(T i = 2; i <= number; ++i) {
        if(!is_prime[i]) primes.push_back(i);
    }
    return primes;
}
// usage:
//   int n = 100;
//   vector<int> primes = sieve<int>(n);
//   {2, 3, 5, 7, ... 83, 89, 97}