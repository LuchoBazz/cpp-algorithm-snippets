template<typename T>
class SegmentTree {
public:
    static const T neutral = T(...);
    struct Node {
        // don't forget to set default value (used for leaves)
        // not necessarily neutral element!
        T lazy = neutral;
        T mx = neutral;
        T mn = neutral;
        T sum = neutral;
        
        bool changed = false;

        void apply(int left, int right, T value) {
            lazy = value;
            mx = value;
            mn = value;
            sum = (right - left + 1) * value;
            changed = true; 
        }
    };

    Node unite(const Node &a, const Node &b) const {
        Node res;
        res.sum = a.sum + b.sum;
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        return res;
    }

    inline void push(int x, int left, int right) {
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        // push from x into (x + 1) and z
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
        if (left <= from && to <= right) return tree[x];
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

    int find_first_knowingly(int x, int left, int right, const function<bool(const Node&)> &f) {
        if (left == right) return left;
        push(x, left, right);
        int y = (left + right) >> 1;
        int z = x + ((y - left + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, left, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, right, f);
        }
        pull(x, z);
        return res;
    }

    int find_first(int x, int from, int to, int left, int right, const function<bool(const Node&)> &func) {
        if (left <= from && to <= right) {
            if (!func(tree[x])) return -1;
            return find_first_knowingly(x, from, to, func);
        }
        push(x, from, to);
        int y = (from + to) >> 1;
        int z = x + ((y - left + 1) << 1);
        int res = -1;
        if (left <= y) {
            res = find_first(x + 1, from, y, left, right, func);
        }
        if (right > y && res == -1) {
            res = find_first(z, y + 1, to, left, right, func);
        }
        pull(x, z);
        return res;
    }

    int find_last_knowingly(int x, int from, int to, const function<bool(const Node&)> &func) {
        if (from == to) return from;
        push(x, from, to);
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        int res;
        if (func(tree[z])) {
            res = find_last_knowingly(z, y + 1, to, func);
        } else {
            res = find_last_knowingly(x + 1, from, y, func);
        }
        pull(x, z);
        return res;
    }

    int find_last(int x, int from, int to, int left, int right, const function<bool(const Node&)> &func) {
        if (left <= from && to <= right) {
            if (!func(tree[x])) return -1;
            return find_last_knowingly(x, from, to, func);
        }
        push(x, from, to);
        int y = (from + to) >> 1;
        int z = x + ((y - from + 1) << 1);
        int res = -1;
        if (right > y) {
            res = find_last(z, y + 1, to, left, right, func);
        }
        if (left <= y && res == -1) {
            res = find_last(x + 1, from, y, left, right, func);
        }
        pull(x, z);
        return res;
    }

    SegmentTree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    SegmentTree(const vector<T> &v) {
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

    // find_first and find_last call all FALSE elements
    // to the left (right) of the sought position exactly once
    int find_first(int left, int right, const function<bool(const Node&)> &func) {
        assert(0 <= left && left <= right && right <= n - 1);
        return find_first(0, 0, n - 1, left, right, func);
    }

    int find_last(int left, int right, const function<bool(const Node&)> &f) {
        assert(0 <= left && left <= right && right <= n - 1);
        return find_last(0, 0, n - 1, left, right, f);
    }
};
template<typename T>
using segtree = SegmentTree<T>;

// Usage:
// segtree<int> st(n);
// st.modify(l, r, val);
// st.query(l, r).(sum, mn, mx)