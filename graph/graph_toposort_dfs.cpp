// Topological Sort - Detecting Cycles
template <typename T>
vector<int> find_toposort(const digraph<T> &g, bool &isCyclic) {
    vector<bool> visited(g.n, false);
    vector<bool> onstack(g.n, false);
    vector<int> toposort;
    function<bool(int)> dfs = [&](int vertex) -> bool {
        visited[vertex] = true;
        onstack[vertex] = true;
        for(link<T> neighbor: g.adj[vertex]) {
            if(visited[neighbor.to] && onstack[neighbor.to]) {
                // There is a circle
                return true;
            } else if(!visited[neighbor.to] && dfs(neighbor.to)) {
                // There is a circle
                return true;
            }
        }
        onstack[vertex] = false;
        toposort.push_back(vertex);
        return false;
    };
    for(int vertex = 0; vertex < g.n; ++vertex) {
        if(!visited[vertex]) {
            isCyclic = isCyclic || dfs(vertex);
            if(isCyclic) break;
        }
    }
    reverse(toposort.begin(), toposort.end());
    return toposort;
}
// Usage:
//   digraph<int> g(n);
//   g.add(..., ...);
//   bool isCyclic = false;
//   vector<int> toposort = find_toposort(g, isCyclic);  
//   if(isCyclic) {...} else {...}