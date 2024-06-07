void divide(int left, int right) {
    if (left == right) {
        return;
    } else if (left < right) {
        int mid = (left + right) / 2;
        divide(left, mid);
        divide(mid + 1, right);
    }
}
