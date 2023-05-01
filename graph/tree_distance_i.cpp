// Problem: Tree Distances I (https://cses.fi/problemset/task/1132)
// You are given a tree consisting of n nodes.
// * Your task is to determine for each node the maximum distance to another node.

using int64 = long long;

const int N = 2e5 + 5;
vector<int> adj[N];
int64 first_dist[N], second_dist[N], dp[N];

// first_dist[i]: farthest distance from the node i-th
// second_dist[i]: second farthest distance from the node i-th

void dfs_dist(int u, int p) {
    first_dist[u] = second_dist[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue; 
        dfs_dist(v, u);
        int d = first_dist[v] + 1;
        if (d > first_dist[u]) {
            second_dist[u] = first_dist[u];
            first_dist[u] = d;
        } else if (d > second_dist[u]) {
            second_dist[u] = d;
        }
    }
}

// pd: Parent Distance
void dfs_dp(int u, int p, int64 pd) {
    dp[u] = max(first_dist[u], pd);
    for (int v : adj[u]) {
        if (v == p) continue;
        int d = first_dist[v] + 1;
        int64 new_pd = pd + 1;
        if (d == first_dist[u]) {
            new_pd = max(new_pd, second_dist[u] + 1);
        } else {
            new_pd = max(new_pd, first_dist[u] + 1);
        }
        dfs_dp(v, u, new_pd);
    }
}

// Usage:
// 1-indexed
// dfs_dist(1, 0);
// dfs_dp(1, 0, 0);
// for(int i = 1; i <= n; i++) cout << dp[i] << " ";

// 0-indexed
// dfs_dist(0, -1);
// dfs_dp(0, -1, 0);
// for(int i = 0; i < n; i++) cout << dp[i] << " ";
