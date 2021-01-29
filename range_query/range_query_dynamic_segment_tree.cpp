template<typename T>
class SegmentTree {
    struct Node {
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
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        res.idx_mx = (res.mx==a.mx)?a.idx_mx:b.idx_mx;
        res.idx_mn = (res.mn==a.mn)?a.idx_mn:b.idx_mn;
        return res;
    }
    void modify(int index, T value) {
        if(low == high) {
            data.apply(low, value);
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
void fill(SegmentTree<T> &st, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); ++i)
        st.modify(i, v[i]);
}

template<typename T>
using segtree = SegmentTree<T>;

// Usage:
// int n = (int) A.size();
// segtree<int> st(0, n-1);
// fill(st, A);