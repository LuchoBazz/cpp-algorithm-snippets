const int mxN = 2e5 + 10;
const int LOG = 20;

vector<int> adj[mxN];
int up[mxN][LOG];
int tin[mxN];
int tout[mxN];
int depth[mxN];
int timer = 0;

void lifting(int node, int parent) {
    tin[node] = ++timer;
    up[node][0] = parent;
    for(int i = 1; i < LOG; ++i) {
        up[node][i] = up[ up[node][i-1] ][i-1];
        // up[node][i] = up[max(0, up[node][i-1])][i-1]; // to use the jump(node, k) function
    }
    for(auto &child: adj[node]) {
        if(child == parent) continue;
        depth[child] = depth[node] + 1;
        lifting(child, node);
    }
    tout[node] = ++timer;
}

bool is_ancestor(int left, int right) {
    return tin[left] <= tin[right] && tout[left] >= tout[right];
}

int lca(int left, int right) {
    if(is_ancestor(left, right)) {
        return left;
    } else if(is_ancestor(right, left)) {
        return right;
    }
    for(int i = LOG-1; i >= 0; i--) {
        if(!is_ancestor(up[left][i], right)) {
            left = up[left][i];
        }
    }
    return up[left][0];
}

// jump k levels up in the tree
int jump(int node, int k) {
    for(int i = 0; i < LOG; ++i) {
        if((k >> i) & 1 && node != -1) {
            node = up[node][i];
        }
    }
    return node;
}

// distance between 2 nodes -> O(lg(n))
// depth[left] + depth[right] − 2*depth[ lca(left, right) ]

// lifting(0, -1); to use the jump(node, k) function
// lifting(0, 0); to use the lca(left, right) function