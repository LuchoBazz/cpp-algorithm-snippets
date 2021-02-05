// misc_y_combinator

// graph_graph

// graph_undigraph
// or
// graph_digraph

template<typename T>
vector<int> find_cycle(const graph<T> &G) {
    vector<int> previous(G.n, -1);
    vector<int> colors(G.n, 0);
    int start_node=-1, end_node=-1;

    auto dfs = y_combinator([&](auto self, const graph<T> &G, int node, int parent) -> bool {
        colors[node] = 1;
        for(const link<T> &neighbor: G.adj[node]) {
            if(neighbor.to == parent)
                continue;
            if(colors[neighbor.to] == 0) {
                previous[neighbor.to] = node;
                if(self(G, neighbor.to, node))
                    return true;
            } else if(colors[neighbor.to] == 1){
                start_node = neighbor.to;
                end_node = node;
                return true;
            }
        }
        colors[node] = 2;
        return false;
    });
    
    for(int i = 0; i < G.n; ++i){
        if(colors[i] == 0 && dfs(G, i, -1))
            break;
    }
    
    if(start_node==-1 || end_node==-1) {
        return vector<int>{}; // There isn't cycle
    } else {
        vector<int> cycle;
        for(int node = end_node; node != -1; node = previous[node]) {
            cycle.push_back(node);
            if(node == start_node)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cycle.push_back(start_node);
        return cycle;
    }
}