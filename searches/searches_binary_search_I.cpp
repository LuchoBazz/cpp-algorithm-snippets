int n = oo;
int low=0, high=n, mid;
while(low < high) {
    mid = low + (high - low) / 2;
    if(!ok(mid)) {
        low = mid + 1;
    } else {
        high = mid;
    }
}
// low