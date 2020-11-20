template<typename T>
bool min_ref(T &x, T y) {
    if(y < x) {x = y; return true;}
    return false;
}

template<typename T>
bool max_ref(T &x, T y) {
    if(y > x) {x = y; return true;}
    return false;
}