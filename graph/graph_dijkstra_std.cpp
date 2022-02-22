// graph_graph

// graph_undigraph
// or
// graph_digraph

template <typename T>
vector <T> dijkstra(const graph<T> &g, int start) {
    assert(0 <= start && start < g.n);
    priority_queue<link<T>, vector<link<T>>, greater<link<T>>> Q;
    vector<T> dist(g.n, numeric_limits<T>::max());
    dist[start] = static_cast<T>(0);
    Q.push({start, static_cast<T>(0)});
    while (!Q.empty()) {
        link<T> node = Q.top(); Q.pop();
        int to = node.to;
        if(node.cost > dist[to]) {
            continue;
        }
        for (link<T> neighbor: g.adj[to]) {
            T newCost = dist[to] + neighbor.cost;
            if (newCost < dist[neighbor.to]) {
                Q.push({neighbor.to, newCost});
                dist[neighbor.to] = newCost;
            }
        }
    }
    return dist;
    // returns numeric_limits<T>::max() if there's no path
}
// Usage:
//   digraph<int> g(n); or undigraph<int> g(n);
//   g.add(from, to, cost);
//   vector<int> dist = dijkstra(g, start);