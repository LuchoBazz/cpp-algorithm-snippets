template<class Fun>
class y_combinator_result {
    Fun funct;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): funct(std::forward<T>(fun)) {}
 
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return funct(ref(*this), forward<Args>(args)...);
    }
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun));
}
// Usage:
// auto go = y_combinator([&](auto Go, int idx) -> int64 {
//     ...
//     return Go(idx-1);
// });
// int64 ans = go(0);