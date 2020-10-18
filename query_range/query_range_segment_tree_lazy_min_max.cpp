template<typename T>
class SegmentTree {
public:

    static const T neutral = oo;

    struct Node {
        T lazy = neutral;
        T ans = neutral;
        bool changed = false;

        void apply(int left, int right, T value) {
            lazy = value;
            ans = value;
            changed = true;
        }
    };

    Node unite(const Node &a, const Node &b) const {
        Node res;
        // res.ans = min(a.ans, b.ans);
        // res.ans = max(a.ans, b.ans);
        return res;
    }

    inline void push(int x, int left, int right) {
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        if (tree[x].lazy != neutral || tree[x].changed) {
            tree[x + 1].apply(left, y, tree[x].lazy);
            tree[z].apply(y + 1, right, tree[x].lazy);
            tree[x].lazy = neutral;
        }
    }

    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }

    int n;
    vector<Node> tree;

    void build(int x, int left, int right) {
        if (left == right) return;
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        build(x + 1, left, y);
        build(z, y + 1, right);
        pull(x, z);
    }

    template <typename M>
    void build(int x, int left, int right, const vector<M> &v) {
        if (left == right) {
            tree[x].apply(left, right, v[left]);
            return;
        }
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        build(x + 1, left, y, v);
        build(z, y + 1, right, v);
        pull(x, z);
    }

    Node query(int x, int from, int to, int left, int right) {
        if (left <= from && to <= right) {
            return tree[x];
        }
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        push(x, from, to);
        Node res{};
        if (right <= y) {
            res = query(x + 1, from, y, left, right);
        } else {
            if (left > y) {
            res = query(z, y + 1, to, left, right);
            } else {
            res = unite(query(x + 1, from, y, left, right), query(z, y + 1, to, left, right));
            }
        }
        pull(x, z);
        return res;
    }

    template <typename... M>
    void modify(int x, int from, int to, int left, int right, const M&... v) {
        if (left <= from && to <= right) {
            tree[x].apply(from, to, v...);
            return;
        }
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        push(x, from, to);
        if (left <= y) {
            modify(x + 1, from, y, left, right, v...);
        }
        if (right > y) {
            modify(z, y + 1, to, left, right, v...);
        }
        pull(x, z);
    }

    SegmentTree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <typename M>
    SegmentTree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    Node query(int left, int right) {
        assert(0 <= left && left <= right && right <= n - 1);
        return query(0, 0, n - 1, left, right);
    }

    Node query(int idx) {
        assert(0 <= idx && idx <= n - 1);
        return query(0, 0, n - 1, idx, idx);
    }

    template <typename... M>
    void modify(int left, int right, const M&... v) {
        assert(0 <= left && left <= right && right <= n - 1);
        modify(0, 0, n - 1, left, right, v...);
    }
};
template<typename T>
using segtree = SegmentTree<T>; 

// Usage:
// segtree<int> st(n); or segtree<int64_t> st({1, 2, 3, ..});
// st.modify(l, r, val);
// st.query(l, r).ans