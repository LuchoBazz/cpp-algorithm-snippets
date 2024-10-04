int64_t ternary_search(const function<int64_t(int64_t)> &func, int64_t low,
                       int64_t high) {

    while (high - low > 2) {
        int64_t delta = (high - low) / 3LL;
        int64_t m1 = low + delta, m2 = high - delta;

        if (func(m1) > func(m2)) { // change to < to find the maximum
            low = m1;
        } else {
            high = m2;
        }
    }
    int64_t best = NEUTRO;
    for (int64_t mid = low; mid <= high; ++mid) {
        best = min(best, func(mid));
    }
    return best;
}
// Usage:
// int64_t best = ternary_search(funct, low, high);
