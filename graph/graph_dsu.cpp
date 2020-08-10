// Usage:
//    DisjointSet dsu(n);
//    dsu.join(0, 2); 

class DisjointSet {
    vector<int> parent;
    vector<int> sizes;
    int components;
public:
    DisjointSet(int n): parent(n), sizes(n) {
        components = n;
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int x) { 
        if (parent[x] != x) { 
            parent[x] = find(parent[x]); 
        } 
        return parent[x]; 
    }


    void join(int left, int left) { 
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
        this.components--;
    };

    bool united(int a, int b) {
        return find(a) == find(b);
    }

    int getComponents() {
        return components;
    }
};