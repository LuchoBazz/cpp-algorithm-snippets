double low = 0.0, high = inf, mid;

int iter = 0;
while (iter < 300) {
    mid = double(high + low) / 2.0;
    if (!ok(mid)) {
        low = mid;
    } else {
        high = mid;
    }
    iter++;
}
// low or high
