template <typename T>
vector<edge<T>> find_kruskal(const undigraph<T> &g, T &ans) {
    vector<edge<T>> edges(g.edges);
    sort(edges.begin(), edges.end(), [&g](const edge<T> &a, const edge<T> &b) {
        return a.cost < b.cost;
    });
    ans = 0;
    vector<edge<T>> mst;
    DisjointSet dsu(g.n);
    for(edge<T> e : edges) {
        if(dsu.unite(e.from, e.to)) {
            mst.push_back(e);
            ans += e.cost;
        }
    }
    return mst;
}
// Usage:
//    int n = ..;
//    undigraph<int> g(n);
//    g.add(..., ..., ...);
//    int cost = 0;
//    vector<edge<int>> mst = find_kruskal(g, cost);