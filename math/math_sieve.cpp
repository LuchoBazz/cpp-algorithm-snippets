class Sieve {
    int maximum;
    vector<int> primes;
    vector<int> smallest_factor;
    vector<bool> isprime;
public:
    
    Sieve() : maximum(-1) {}

    Sieve(int mx) : maximum(mx) {
        assert(0 <= mx);
        isprime.resize(maximum+1, true);
        smallest_factor.resize(maximum+1, 0);
        
        smallest_factor[0] = smallest_factor[1] = 1;
        isprime[0] = isprime[1] = false;
        
        for(int prime = 2; prime <= maximum; ++prime) {
            if(isprime[prime]) {
                primes.push_back(prime);
                smallest_factor[prime] = prime;
                for(int64_t j = 1LL*prime*prime; j <= maximum; j += prime) {
                    if(isprime[j]) {
                        isprime[j] = false;
                        smallest_factor[j] = prime;
                    }
                }
            }
        }
    }

    int prime_kth(int k) {
        // returns the k-th prime (1-indexed)
        assert(1 <= k && k <= (int) primes.size());
        return primes[k-1];
    }
    
    int size_primes() {
        // number of primes from 0 to maximum (inclusive)
        return (int) primes.size();
    }

    int smallest(int number) { // smallest prime factor of a number
        assert(1 <= number && number <= maximum);
        return smallest_factor[number];
    }

    bool is_prime(int number) {
        assert(0 <= number && number <= maximum);
        return isprime[number];
    }

    bool operator[](int number) {
        return is_prime(number);
    }
};