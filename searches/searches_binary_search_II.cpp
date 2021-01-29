int n = oo;
int low = 0, high = n, mid;
while (high - low > 1) {
    mid = low + (high - low) >> 1;
    if(!ok(mid)) {
        low = mid;
    } else {
        high = mid;
    }
}
// low or high