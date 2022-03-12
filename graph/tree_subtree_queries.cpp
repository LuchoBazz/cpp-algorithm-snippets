const int mxN = 2e5 + 10;
vector<int> adj[mxN];
int n, q;

int ids[mxN]; // Node ID
// Subtree Range: [ids[node], tout[node]]
int tout[mxN]; // useful for calculating the query range
int sub[mxN]; // Subtree Size
int values[mxN]; // Node Values
int timer = 0;

void dfs(int node, int parent) {
    sub[node] = 1;
    ids[node] = timer++;
    for(int &child: adj[node]) {
        if(child == parent) continue;
        dfs(child, node);
        sub[node] += sub[child];
    }
    tout[node] = timer - 1;
}
// Start the query structure
//     forn(i, n) st.modify(ids[i], values[i]);
// Update a tree Node
//     st.modify(ids[idx], val);
// query on the subtree of a node, including the node
//     st.query(ids[node], tout[node])
// Run dfs
//     dfs(0, 0)