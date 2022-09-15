double ternary_search(const function<double(double)> &func, double low, double high) {
    int it = 0;
    while (it < 100) { // with 50 iterations it has precision for 1e-9
        double diff = (high - low) / 3.0;
        double mid1 = low + diff;
        double mid2 = high - diff;

        double f1 = func(mid1);
        double f2 = func(mid2);

        if (f1 > f2) // change to < to find the maximum
            low = mid1;
        else
            high = mid2;
        it++;
    }
    return func(low);
}
// Usage:
// double ans = ternary_search(funct1, low, high);