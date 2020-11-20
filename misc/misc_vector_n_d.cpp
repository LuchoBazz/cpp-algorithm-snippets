#define vt vector

template<typename T>
vt<vt<T>> vector2d(int x1, int x2, T default_value=T()) {
    return vt<vt<T>>(x1, vt<T>(x2, default_value));
}
template<typename T>
vt<vt<vt<T>>> vector3d(int x1, int x2, int x3, T default_value=T()) {
    return vt<vt<vt<T>>>(x1, vector2d<T>(x2, x3, default_value));
}
template<typename T>
vt<vt<vt<vt<T>>>> vector4d(int x1, int x2, int x3, int x4, T default_value=T()) {
    return vt<vt<vt<vt<T>>>>(x1, vector3d<T>(x2, x3, x4, default_value));
}
template<typename T>
vt<vt<vt<vt<vt<T>>>>> vector5d(int x1, int x2, int x3, int x4, int x5, T default_value=T()) {
    return vt<vt<vt<vt<vt<T>>>>>(x1, vector4d<T>(x2, x3, x4, x5, default_value));
}