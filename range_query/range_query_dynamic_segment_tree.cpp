template <typename T> struct Node {
    // set default values
    T sum = ...;
    T mx = ...;
    T mn = ...;
    int idx_mx = -1;
    int idx_mn = -1;
    // apply: set values for leaves
    void apply(int index, T value) {
        sum = value;
        mx = value;
        mn = value;
        idx_mx = index;
        idx_mn = index;
    }
};

template <typename T> class SegmentTree {
    SegmentTree<T> *left, *right;
    int low, high, mid;
    Node<T> data;

    SegmentTree(int low, int high) : low(low), high(high), data{} {
        mid = (high + low) / 2;
        if (low != high) {
            left = new SegmentTree<T>(low, mid);
            right = new SegmentTree<T>(mid + 1, high);
        }
    }

public:
    SegmentTree(const vector<T> &v) {
        low = 0;
        high = int(v.size()) - 1;
        mid = (high + low) / 2;
        if (low != high) {
            left = new SegmentTree<T>(low, mid);
            right = new SegmentTree<T>(mid + 1, high);
        }
        int idx = 0;
        for (const T &x : v) {
            this->modify(idx++, x);
        }
    }

    inline Node<T> unite(const Node<T> &a, const Node<T> &b) {
        Node<T> res;
        res.sum = a.sum + b.sum;
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        res.idx_mx = (res.mx == a.mx) ? a.idx_mx : b.idx_mx;
        res.idx_mn = (res.mn == a.mn) ? a.idx_mn : b.idx_mn;
        return res;
    }

    inline void modify(int index, T value) {
        if (low == high) {
            data.apply(low, value);
        } else {
            if (index <= mid)
                left->modify(index, value);
            else
                right->modify(index, value);
            data = unite(left->data, right->data);
        }
    }

    inline Node<T> query(int a, int b) {
        if (a > high || b < low)
        return Node<T>{};
        if (a <= low && high <= b)
        return data;
        return unite(left->query(a, b), right->query(a, b));
    }
};

template <typename T> using segtree = SegmentTree<T>;
// Usage:
// segtree<int64> st(v);
// st.query(l, r).sum;
// st.modify(idx, value);