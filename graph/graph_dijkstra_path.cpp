// graph_graph

// graph_undigraph
// or
// graph_digraph

template<typename T>
pair<vector<T>, vector<int>> dijkstra(const graph<T> &G, int start) {
    vector<T> dist(G.n, numeric_limits<T>::max());
    vector<int> prev(G.n, -1);
    dist[start] = T(0);
    priority_queue<link<T>, vector<link<T>>, greater<link<T>>> Q;
    Q.push({start, T(0)});
    while(!Q.empty()) {
        link<T> node = Q.top(); Q.pop();
        for(const link<T> &neighbor: G.adj[node.to]) {
            T new_cost = dist[node.to] + neighbor.cost;
            if(new_cost < dist[neighbor.to]) {
                dist[neighbor.to] = new_cost;
                prev[neighbor.to] = node.to;
                Q.push(neighbor);
            }
        }
    }
    return {dist, prev};
}

template<typename T>
bool check_path(const vector<T> &dist, int end) {
    return dist[end] != numeric_limits<T>::max();
}
 
vector<int> rebuild_path(const vector<int> &prev, int end) {
    vector<int> path;
    for(int node = end; node != -1; node = prev[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());
    return path;
}

// Usage:

// auto [dist, prev] = dijkstra(G, start);
// if(check_path(dist, end)) {
//    vector<int> path = rebuild_path(prev, end);
// } else {
//    There is no path
// }