const double PI = 3.141592653589793238462643383279502884L;

template<typename T>
void fft(vector<complex<T>> &a, bool invert=false) {
    assert(is_floating_point<T>::value);
    int n = (int) a.size();
    if (n == 1) return;
    vector<complex<T>> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
    T angle = 2 * (PI / n) * (invert ? -1 : 1);
    complex<T> w(1);
    complex<T> wn(cos(angle), sin(angle));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}