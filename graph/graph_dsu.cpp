class DisjointSet {
    vector<int> parents;
    vector<int> sizes;
    int comps;
public:
    DisjointSet(int n): parents(n), sizes(n) {
        comps = n;
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int x) { 
        if (parents[x] != x) { 
            parents[x] = find(parents[x]); 
        } 
        return parents[x]; 
    }

    void unite(int left, int right) { 
        int x = find(left);
        int y = find(right);
        if(x == y) return;
        if(sizes[x] < sizes[y]) {
            sizes[y] += sizes[x];
            parents[x] = y;
        } else if(sizes[x] >= sizes[y]) {
            sizes[x] += sizes[y];
            parents[y] = x;
        }
        comps--;
    };

    bool united(int left, int right) {
        return find(left) == find(right);
    }

    int getComps() {
        return comps;
    }
};
// Usage:
//    DisjointSet dsu(n);
//    dsu.unite(0, 2); 