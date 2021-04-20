template <typename T, typename Operate>
class SparseTable {
public:
    int n;
    vector<vector<T>> table;
    Operate func;

    SparseTable(const vector<T>& v) {
        n = (int) v.size();
        int max_log = 32 - __builtin_clz(n);
        table.resize(max_log);
        table[0] = v;
        for (int j = 1; j < max_log; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(table[lg][from], table[lg][to - (1 << lg) + 1]);
    }
};

struct Min {
    template <typename T> T operator()(T x, T y) const { return min<T>(x, y); } };
struct Max {
    template <typename T> T operator()(T x, T y) const { return max<T>(x, y); } };
struct Add {
    template <typename T> T operator()(T x, T y) const { return x+y; } };

template<typename T> using SparseTMin = SparseTable<T, Min>;
template<typename T> using SparseTMax = SparseTable<T, Max>;
template<typename T> using SparseTAdd = SparseTable<T, Add>;