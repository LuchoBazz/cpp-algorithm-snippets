template<typename T>
class SegmentTree {
    static const T neutral = T(...);
    struct Node {
        T sum = neutral;
        T mn = neutral;
        int idx_mn = -1;
        void apply(int left, int right, T value) {
            sum = value;
            mn = value;
            if(left == right) idx_mn = left;
        }
    };
    SegmentTree<T> *left, *right;
    int low, high, mid;
    Node data;
public:
    SegmentTree(int low, int high) : low(low), high(high), data{} {
        if(low != high) {
            mid = low + (high - low)/2;
            left = new SegmentTree<T>(low, mid);
            right = new SegmentTree<T>(mid+1, high);
        }
    }
    Node unite(const Node &a, const Node &b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.idx_mn = (res.mn==a.mn)?a.idx_mn:b.idx_mn;
        return res;
    }
    void modify(int index, T value) {
        if(low == high) {
            data.apply(low, high, value);
        } else {
            if(index <= mid) left->modify(index, value);
            else right->modify(index, value);
            data = unite(left->data, right->data);
        }
    }
    Node query(int a, int b) {
        if(a > high || b < low) return Node{};
        if(a <= low && high <= b) return data;
        return unite(left->query(a, b), right->query(a, b));
    }
};

template<typename T>
void fill(SegmentTree<T> &st, const vector<T> &values) {
    for(int i = 0; i < int(values.size()); ++i) {
        st.modify(i, values[i]);
    }
}

template<typename T>
using segtree = SegmentTree<T>;

// Usage:
// segtree<int> st(0, int(values.size())-1);
// fill(st, values);
