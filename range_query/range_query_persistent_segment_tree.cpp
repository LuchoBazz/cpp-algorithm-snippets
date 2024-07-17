template <typename T> struct Data {
    // set default values
    T sum = 0;
    T mx = 0;
    T mn = 0;
    int idx_mx = -1;
    int idx_mn = -1;
    // apply: set values for leaves
    void apply(int index, T value) {
        sum += value;
        mx += value;
        mn += value;
        idx_mx = index;
        idx_mn = index;
    }
};

template <typename T> class NodeST {
  public:
    NodeST<T> *left, *right;
    int low, high;
    Data<T> data;
    NodeST() : left(NULL), right(NULL), data(Data<T>()) {}
    NodeST(Data<T> v) : left(NULL), right(NULL), data(v) {}
    NodeST(NodeST *l, NodeST *r, Data<T> v) : left(l), right(r), data(v) {}
};

template <typename T> class PersistentSegmentTree {
  public:
    void build(NodeST<T> *node, const vector<T> &v, int low, int high) {
        if (low == high)
            return node->data.apply(low, v[low]);
        int mid = low + (high - low) / 2;
        node->left = new NodeST<T>();
        node->right = new NodeST<T>();
        build(node->left, v, low, mid);
        build(node->right, v, mid + 1, high);
        pull(node);
    }
    inline Data<T> unite(const Data<T> &a, const Data<T> &b) {
        Data<T> res;
        res.sum = a.sum + b.sum;
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        res.idx_mn = (res.mn == a.mn ? a.idx_mn : b.idx_mn);
        res.idx_mx = (res.mx == a.mx ? a.idx_mx : b.idx_mx);
        return res;
    }
    inline void pull(NodeST<T> *node) {
        node->data = unite(node->left->data, node->right->data);
    }
    void upgrade(NodeST<T> *prev, NodeST<T> *current, int low, int high,
                 int idx, int value) {
        if (idx > high || idx < low || low > high)
            return;
        if (low == high)
            return current->data.apply(low, value);
        int mid = low + (high - low) / 2;
        if (idx <= mid) {
            current->right = prev->right;
            current->left = new NodeST<T>(prev->left->data);
            upgrade(prev->left, current->left, low, mid, idx, value);
        } else {
            current->left = prev->left;
            current->right = new NodeST<T>(prev->right->data);
            upgrade(prev->right, current->right, mid + 1, high, idx, value);
        }
        pull(current);
    }
    Data<T> query(NodeST<T> *node, int low, int high, int left, int right) {
        if (left > high || right < low || low > high)
            return Data<T>{};
        if (left <= low && high <= right)
            return node->data;
        int mid = low + (high - low) / 2;
        Data<T> p1 = query(node->left, low, mid, left, right);
        Data<T> p2 = query(node->right, mid + 1, high, left, right);
        return unite(p1, p2);
    }

    int sz;
    vector<NodeST<T> *> version;

    PersistentSegmentTree(const vector<T> &v) {
        sz = (int)v.size();
        version.push_back(new NodeST<T>());
        build(version.back(), v, 0, sz - 1);
    }
    void modify(int from, int to, int idx, T value) {
        int n = (int)version.size();
        assert(0 <= from && from < n && 0 <= to && to < n);
        upgrade(version[from], version[to], 0, sz - 1, idx, value);
    }
    int modify(int from, int idx, T value) {
        int n = (int)version.size();
        assert(0 <= from && from < n);
        version.push_back(new NodeST<T>());
        upgrade(version[from], version.back(), 0, sz - 1, idx, value);
        return (int)version.size() - 1;
    }
    Data<T> query(int from, int low, int high) {
        int n = (int)version.size();
        assert(0 <= from && from < n);
        assert(0 <= low && low < sz && 0 <= high && high < sz && low <= high);
        return query(version[from], 0, sz - 1, low, high);
    }
};

template <typename T> using persist_segtree = PersistentSegmentTree<T>;
