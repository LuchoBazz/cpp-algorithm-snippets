template <typename T>
class SCC {
private:
    digraph<T> g;
    digraph<T> g_rev;
    vector<bool> visited;
    stack<int> toposort;
    vector<vector<int>> components;

    // Topological Sort
    void toposort_dfs(int node) {
        visited[node] = true;
        for(link<T> neighbor: g.adj[node]) {
            if(!visited[neighbor.to]) {
                toposort_dfs(neighbor.to);
            }
        }
        toposort.push(node);
    }

    // dfs Standard
    void dfs(int node) {
        visited[node] = true;
        components.back().push_back(node);
        for(link<T> neighbor: g_rev.adj[node]) {
            if(!visited[neighbor.to]) {
                dfs(neighbor.to);
            }
        }
    }

public:

    SCC(digraph<T> gr) : g(0), g_rev(0) {
        g = gr;
        g_rev = gr.reverse();
        visited.resize(g.n, false);
    }

    // Build Algorithm
    vector<vector<int>> find_scc() {
        components.clear();
        toposort = stack<int>();
        for(int node = 0; node < g.n; ++node) {
            if(!visited[node]) {
                toposort_dfs(node);
            }
        }
        fill(visited.begin(), visited.end(), false);
        while(!toposort.empty()) {
            int node = toposort.top();
            toposort.pop();
            if(!visited[node]) {
                components.push_back(vector<int>{});
                dfs(node);
            }
        }
        return components;
    }
};
// Time Complexity: O(|V| + |E|), Space Complexity: O(|V|)
// |V|: Number of vertices
// |E|: Number of edges

// int n = 8;
// digraph<int> g(n);
// g.add(..., ...);
// SCC<int> scc(g);
// vector<vector<int>> comp = scc.find_scc(); { {0, 1, 2}, {3}, {4, 7, 6, 5} }