const int M = 1e6 + 2;
bool marked[M+1];
vector<int> primes;

// Time: O(M*log(log(M)))
void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= M; i++) {
        if (marked[i]) continue;
        primes.push_back(i);
        for (int64_t j = 1LL * i * i; j <= M; j += i)
            marked[j] = true;
    }
}