const int mxN = 2e5 + 10;
vector<int> adj[mxN];
int tour[2 * mxN]; // Euler Tour
int timer = 0;

void eulerTree(int node, int parent) {
    tour[timer++] = node;
    for(int &child: adj[node]) {
        if(child == parent) continue;
        eulerTree(child, node);
        tour[timer++] = node;
    }
}
//        1
//       / \
//      2   3
//         / \
//        4   5

// for(int i = 0; i < 2*n-1; ++i) cout << tour[i] + 1 << " \n" [i == (2*n-2)];
// Euler Tour: 1 2 1 3 4 3 5 3 1