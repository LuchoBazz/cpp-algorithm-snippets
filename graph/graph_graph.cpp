template <typename T>
class graph {
public:
    struct edge {
        int from;
        int to;
        T cost;
    };
    struct link {
        int to;
        T cost;
        bool operator>(const link& other) const {return cost > other.cost;}
        bool operator<(const link& other) const {return cost < other.cost;}
    };
    vector<edge> edges;
    vector<vector<link>> adj;
    int n;
    graph(int sz) : n(sz) {
        adj.resize(n);
    }
    virtual void add(int from, int to, T cost) = 0;
};