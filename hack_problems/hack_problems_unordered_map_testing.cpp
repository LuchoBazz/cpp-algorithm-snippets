// ref article: https://codeforces.com/blog/entry/62393 (written by Neal Wu)

void insert_numbers(int64_t x) {
    const int N = 2e5;

    clock_t begin = clock();
    unordered_map<int64_t, int> numbers;

    for (int i = 1; i <= N; i++) {
        numbers[i * x] = i;
    }

    int64_t sum = 0LL;

    for (auto &entry : numbers)
        sum += (entry.first / x) * entry.second;

    printf("x = %lld: %.3lf seconds, sum = %lld\n", x, (double) (clock() - begin) / CLOCKS_PER_SEC, sum);
}
// prime numbers that generate collisions in unordered_map or unordered_set

// for: GNU G++17 7.3.0
//     N: 1e5
//     prime: 107897,  time: 2.377 s (approximately)

// for: GNU G++17 9.2.0 (Bit, msys 2)
//     N: 1e5
//     prime: 126271,  time: slow (approximately)

// for: GNU G++11 5.1.0
//     N: 1e5
//     prime: 62233,  time: 3.832 s (approximately)
//     prime: 126271, time: 1.805 s (approximately)

// for: GNU G++14 6.4.0
//     N: 1e5
//     prime: 62233,  time: 4.029 s (approximately)
//     prime: 126271, time: 1.897 s (approximately)

// for: g++ (Ubuntu 10.2.0-13ubuntu1) 10.2.0
//     N: 1e5
//     prime: 42043,  time:  6.582 s (approximately)