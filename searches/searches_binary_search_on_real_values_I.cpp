double eps = 1e-9;
double low = 0.0, high = inf, mid;

while ((high - low) > eps) {
    mid = double(high + low) / 2.0;
    if (!works(mid)) {
        low = mid;
    } else {
        high = mid;
    }
}

// low or high
