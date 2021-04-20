// random_init

template<typename T>
vector<T> random_vector(int n, T from, T to) {
    vector<T> values(n);
    for(int i = 0; i < n; ++i) {
        values[i] = random<T>(from, to);
    }
    return values;
}