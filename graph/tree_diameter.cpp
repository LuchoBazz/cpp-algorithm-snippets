// const int mxN = 1e5;
int dp[mxN];
int dfs(int node, int parent) {
    int mx = 0;
    int first = 0, second=0;
    for(int &child: adj[node]) {
        if(child == parent) continue;
        int factor = dfs(child, node) + 1;
        mx = max(mx, factor);
        if(factor >= first) {
            second = first;
            first = factor;
        } else if(factor >= second) {
            second = factor;
        }
    }
    dp[node] = first + second;
    return mx;
}
// n: number of nodes
// dfs(0, 0);
// int diameter = *max_element(dp, dp + n);