template <typename T>
struct edge {
    int from;
    int to;
    T cost;
};

template <typename T>
struct link {
    int to;
    T cost;
    bool operator>(const link& other) const {return cost > other.cost;}
    bool operator<(const link& other) const {return cost < other.cost;}
};

template <typename T>
class graph {
public:
    vector<edge<T>> edges;
    vector<vector<link<T>>> adj;
    int n;
    graph(int sz) : n(sz) {
        adj.resize(n);
    }
    virtual void add(int from, int to, T cost) = 0;
};