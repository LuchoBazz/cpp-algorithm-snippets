template <class T, class S>
inline bool xmax(T &a, const S &b) {
    return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool xmin(T &a, const S &b) {
    return (a > b ? a = b, 1 : 0);
}