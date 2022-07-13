int diff[mxN]; // Difference Array
int answer[mxN]; // Array after propagation of differences

void dfs(int node, int parent) {
    answer[node] = diff[node];
    for(int &child: adj[node]) {
        if(child == parent) continue;
        dfs(child, node);
        answer[node] += answer[child];
    }
}

// main()
for(int i = 0; i < m; ++i) {
    int l, r; cin >> l >> r, l--, r--;
    int anc = lca(l, r);
    diff[l]++;
    diff[r]++;
    diff[anc]--;
    if(anc != 0)
        diff[up[anc][0]]--;
}

dfs(0, -1);

for(int i = 0; i < n; ++i) {
    cout << answer[i] << " \n" [i == (n-1)];
}

//       [1] -1  -> parent of lca
//       / \
//     [2] [3] -1   -> lca
//         / \
//    +1 [4] [5] +1