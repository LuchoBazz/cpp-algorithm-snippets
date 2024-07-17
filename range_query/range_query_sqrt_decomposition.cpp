/**
 * Description: Square Root Decomposition
 * Verification:
 * t.ly/BMP9
 */

template <typename T> struct Node {
    T mn = numeric_limits<T>::max();
    T mx = numeric_limits<T>::min();
    T add = static_cast<T>(0);

    void apply(T value) {
        mn = value;
        mx = value;
        add = value;
    }

    Node<T> join(T value) {
        mn = min(mn, value);
        mx = max(mx, value);
        add += value;
        return *this;
    }

    Node<T> join(Node<T> other) {
        mn = min(mn, other.mn);
        mx = max(mx, other.mx);
        add += other.add;
        return *this;
    }
};

template <typename T> struct bucket {
    int left, right;
    vector<T> *values;

    T lazy;
    Node<T> data;

    bucket(int l, int r, vector<T> *v) : left(l), right(r), values(v) {
        lazy = static_cast<T>(0);
    }

    void build() {
        for (int i = left; i <= right; i++) {
            values->at(i) += lazy;
        }
        data = Node<T>();
        for (int i = left; i <= right; i++) {
            data = data.join(values->at(i));
        }
        lazy = 0;
    }

    void update(int L, int R, T v) {
        if (L <= left && right <= R) {
            lazy += v;
        } else {
            for (int i = max(L, left); i <= min(R, right); i++) {
                values->at(i) += v;
            }
            build();
        }
    }

    Node<T> query(int L, int R) {
        Node<T> ans;
        if (L <= left && right <= R) {
            ans.apply(data.mn + lazy);
        } else {
            build();
            for (int i = max(L, left); i <= min(R, right); i++) {
                ans = ans.join(values->at(i));
            }
        }
        return ans;
    }
};

template <typename T> struct SqrtDecomposition {
    vector<bucket<T>> table;
    vector<T> a;
    int len;

    SqrtDecomposition(vector<T> &v) : a(v) {
        int n = (int)v.size();
        len = (int)sqrt(n) + 1;
        table.reserve(len + 1);

        int l = 0, r = len;
        for (int i = 0; i < len; ++i) {
            int from = l, to = min(n - 1, r - 1);
            table.push_back(bucket<T>(from, to, &a));
            l += len;
            r += len;
            table.back().build();
        }
    }

    Node<T> query(int from, int to) {
        int from_bucket = from / len, to_bucket = to / len;
        Node<T> ans;
        for (int i = from_bucket; i <= to_bucket; ++i) {
            ans = ans.join(table[i].query(from, to));
        }
        return ans;
    }

    void modify(int from, int to, int value) {
        int from_bucket = from / len, to_bucket = to / len;
        for (int i = from_bucket; i <= to_bucket; ++i) {
            table[i].update(from, to, value);
        }
    }
};

template <typename T> using sqrt_d = SqrtDecomposition<T>;

// Usage:
//   vector<int> a(...);
//   sqrt_d<int> sd(a);
