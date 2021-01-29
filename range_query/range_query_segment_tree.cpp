template <typename T, class F = function<T(const T&, const T&)>>
class SegmentTree {
    T NEUTRAL;
    int n;
    vector<T> tree;
    F func;
public:
    
    SegmentTree(const vector<T> &values, T neutral, const F& f) : func(f) {
        NEUTRAL = neutral;
        n = values.size();
        tree.resize(n*2);
        // Build
        for (int i=0; i < n; i++) {
            tree[n+i] = values[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = func(tree[i*2], tree[i*2+1]);
        }
    }
    
    void modify(int index, T value) {
        tree[index+n] = value;
        index = index + n;
        for (int i = index; i > 1; i >>= 1){
            tree[i/2] = func(tree[i], tree[i^1]);
        }
    }
    
    T query(int l, int r) {
        T ans = NEUTRAL;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                ans = func(ans, tree[l++]);
            }
            if (r&1) {
                ans = func(ans, tree[--r]);
            }
        }
        return ans;
    }
};
template<typename T>
using segtree = SegmentTree<T>;
// usage:
//  auto func = [&](int i, int j) -> int { return max(i, j); };
//  segtree<int, decltype(func)> st(values, -oo, func);
// or:
// segtree<int> st(values, -oo, [&](int x, int y) -> int {return max(x, y);});