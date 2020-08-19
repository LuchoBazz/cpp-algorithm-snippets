template<typename T>
void amin(T &x, T y) {
    if(y < x) x = y;
}

template<typename T>
void amax(T &x, T y) {
    if(y > x) x = y;
}