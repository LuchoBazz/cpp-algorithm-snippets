template <typename T>
class graph {
public:
    struct edge {
        int from;
        int to;
        T cost;
    };
    vector<edge> edges;
    vector<vector<pair<T, int>>> adj;
    int n;
    graph(int _n) : n(_n) {
        adj.resize(n);
    }
    virtual void add(int from, int to, T cost) = 0;
};