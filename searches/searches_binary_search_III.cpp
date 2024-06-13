int low = -1, high = oo;
for (int delta = high + 1; delta >= 1; delta /= 2) {
    while (delta + low < high && !works(delta + low)) {
        low += delta;
    }
}
// answer: low + 1
