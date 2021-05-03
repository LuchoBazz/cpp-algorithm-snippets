template<typename T>
inline bool between(T a, T b, T c) { return (a <= b && b <= c); }
// #define between(a, b, c) (a <= b && b <= c)
#define has_key(it, key) (it.find(key) != it.end())
#define check_coord(x, y, n, m) (0 <=x && x < n && 0 <= y && y < m)