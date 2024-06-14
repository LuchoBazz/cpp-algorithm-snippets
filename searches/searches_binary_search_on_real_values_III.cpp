double low = 0.0, high = inf, delta = inf;
for (int iter = 0; iter < 100; ++iter) {
    if (delta + low < high && !works(delta + low)) {
        low += delta;
    }
    delta /= 2.0;
}
// low
