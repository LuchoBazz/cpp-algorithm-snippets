#ifdef ONLINE_JUDGE
// Reference: https://codeforces.com/blog/entry/96344
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#define endl '\n'
#define _ << ' ' <<
#define PB push_back
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define overload4(a, b, c, d, e, ...) e
#define for1(a) for (int i = 0; i < int(a); ++i)
#define for2(i, a) for (int i = 0; i < int(a); ++i)
#define for3(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define for4(i, a, b, c) for (int i = int(a); i <= int(b); i += int(c))
#define rof1(a) for (int i = int(a) - 1; i >= 0; --i)
#define rof2(i, a) for (int i = int(a) - 1; i >= 0; --i)
#define rof3(i, a, b) for (int i = int(b); i >= int(a); --i)
#define rof4(i, a, b, c) for (int i = int(b); i >= int(a); i -= int(c))
#define forn(...) overload4(__VA_ARGS__, for4, for3, for2, for1)(__VA_ARGS__)
#define rof(...) overload4(__VA_ARGS__, rof4, rof3, rof2, rof1)(__VA_ARGS__)

const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const string YES = "YES", NO = "NO";

const int d4x[4] = {0, -1, 1, 0};
const int d4y[4] = {-1, 0, 0, 1};
const int d8x[8] = {-1, 0, -1, 1, -1, 1, 0, 1};
const int d8y[8] = {-1, -1, 0, -1, 1, 0, 1, 1};

template <class T, class S> inline bool xmax(T &a, const S &b) {
    return (a < b ? a = b, 1 : 0);
}
template <class T, class S> inline bool xmin(T &a, const S &b) {
    return (a > b ? a = b, 1 : 0);
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto const &i : v)
        os << i << " ";
    os << "\n";
    return os;
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); ++i)
        is >> v[i];
    return is;
}
template <typename T, typename Sequence = vector<T>, typename Compare = less<T>>
using template_heap = priority_queue<T, Sequence, Compare>;
template <typename T> using max_heap = template_heap<T>;
template <typename T> using min_heap = template_heap<T, vector<T>, greater<T>>;

#define pop_heap(heap)                                                         \
    heap.top();                                                                \
    heap.pop();

template <typename Container>
auto get_min(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    return *c.begin();
}

template <typename Container>
auto get_max(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    return *c.rbegin();
}

template <typename Container>
auto erase_min(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    auto to_return = get_min(c);
    c.erase(c.begin());
    return to_return;
}

template <typename Container>
auto erase_max(Container &c) -> typename Container::value_type {
    assert(!c.empty());
    auto to_return = get_max(c);
    c.erase(--c.end());
    return to_return;
}
template <typename T> inline void make_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
}

#define merge_set(big, small) big.insert(small.begin(), small.end());
#define has_key(it, key) (it.find(key) != it.end())

#define MAX(v) (*std::max_element(std::begin(v), std::end(v)))
#define MIN(v) (*std::min_element(std::begin(v), std::end(v)))
#define SUM(v) (std::accumulate(std::begin(v), std::end(v), 0LL))
#define COUNT(v, item) (std::count(std::begin(v), std::end(v), item))

using ll = long long;
using ld = long double;
using i16 = short;

#ifdef DEBUG
#include "../debug.h"
#else
#define log(...) 42
#endif
