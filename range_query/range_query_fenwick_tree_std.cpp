template <typename T>
class Fenwick {
public:
    vector<T> fenw;
    int n;

    Fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }

    T query(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    // Just of + operator
    // T query(int l, int r) {
    //     return query(r) - query(l - 1);
    // }
};

template<typename T>
using fenwick = Fenwick<T>;

struct node {
    // don't forget to set default value
    int a = ...;
    inline void operator+=(const node &other) {
        ...
    }
    inline node operator-(const node &other) {
        ...
        return *this;
    }
};