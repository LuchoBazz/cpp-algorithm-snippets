// graph_graph

// graph_undigraph

template<typename T>
vector<T> bellman_ford(const undigraph<T> &G, int source, bool &cycle) {
    assert(0 <= source && source < G.n);
    T inf = T(numeric_limits<T>::max() / 2);
    vector<T> dist(G.n, inf);
    dist[source] = T(0);
    for(int i = 0; i < G.n + 1; ++i){
        for(const edge<T> &e: G.edges) {
            if(dist[e.from] + e.cost < dist[e.to] && dist[e.from] != inf) {
                dist[e.to] = dist[e.from] + e.cost;
                if(i == n) cycle = true; // There are negative edges
            }
        }
    }
    return dist;
    // Time Complexity: O(V*E), Space Complexity: O(V)
}

// Usage:
// bool cycle = false;
// vector<int> dist = bellman_ford(G, src, cycle);