// const int N = @@;
// int n;
// vector<int> adj[N];

namespace decomposition {
    int subtree[N], depth[N], f[N];

    int dfs(int u, int p = -1) {
        subtree[u] = 1;
        for(const auto &v: adj[u])
            if(v != p)
                subtree[u] += dfs(v, u);
        return subtree[u];
    }

    int get_centroid(int u, int sz, int p = -1) {
        for(const auto &v: adj[u])
            if(!depth[v] && v != p && subtree[v] > sz)
                return get_centroid(v, sz, u);
        return u;
    }

    int decompose(int u, int d=1) {
        int centroid = get_centroid(u, dfs(u) / 2);
        depth[u] = d;
        for(const auto &v: adj[u])
            if(!depth[v])
                f[decompose(v, d + 1)] = centroid;
        return centroid;
    }

    int lca(int u, int v) {
        for(; u != v; u = f[u])
            if(depth[v] > depth[u])
                swap(u, v);
        return u;
    }

    void clean(int n) {
        for(int i = 0; i < n; ++i){
            subtree[i] = 0;
            depth[i] = 0;
            f[i] = 0;
        }
    }

    vector<int> get_centroids() {
        vector<int> centroids;
        // clean(n);
        dfs(0);
        int centroid = get_centroid(0, n / 2);
        centroids.push_back(centroid);
        clean(n);
        dfs(centroid);
        for(const auto &v: adj[centroid])
            if((subtree[centroid] - subtree[v]) == n / 2)
                centroids.push_back(v);
        assert(0 < (int) centroids.size() && (int) centroids.size() <= 2);
        return centroids;
    }
}

using namespace decomposition;
