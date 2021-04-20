template<typename T>
vector<T> random_permutation(int n, T start = 0) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<T> permutation(n);
    iota(permutation.begin(), permutation.end(), start);
    shuffle(permutation.begin(), permutation.end(), rng);
    return permutation;
}