template<typename T>
void min_ref(T &x, T y) {
    if(y < x) x = y;
}

template<typename T>
void max_ref(T &x, T y) {
    if(y > x) x = y;
}