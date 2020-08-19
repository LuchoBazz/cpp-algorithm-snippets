template <typename T>
class digraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::adj;
    using graph<T>::n;

    digraph(int sz) : graph<T>(sz) {}

    void add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        edges.push_back({from, to, cost});
        adj[from].push_back({to, cost});
    }
    
    digraph<T> reverse() const {
        digraph<T> rev(n);
        for (auto &e : edges) {
            rev.add(e.to, e.from, e.cost);
        }
        return rev;
    }
};