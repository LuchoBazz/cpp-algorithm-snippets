class DisjointSet {
    int n;
    vector<int> parents;
    vector<int> sizes;
public:
    
    int comps;
 
    DisjointSet(int _n): n(_n), parents(n), sizes(n), comps(n) {
        fill(sizes.begin(), sizes.end(), 1);
        iota(parents.begin(), parents.end(), 0);
    }
 
    int find(int x) { 
        assert(0 <= x && x < n);
        if (parents[x] != x)
            parents[x] = find(parents[x]); 
        return parents[x]; 
    }
 
    bool unite(int left, int right) {
        assert(0 <= left && left < n);
        assert(0 <= right && right < n); 
        int x = find(left);
        int y = find(right);
        if(x == y)
            return false;
        if(sizes[x] < sizes[y])
            swap(x, y);
        sizes[x] += sizes[y];
        parents[y] = x;
        comps--;
        return true;
    };
 
    bool united(int left, int right) {
        assert(0 <= left && left < n);
        assert(0 <= right && right < n);
        return find(left) == find(right);
    }
 
    int size(int x) {
        assert(0 <= x && x < n);
        return sizes[find(x)];
    }
 
    int id(int x) {
        assert(0 <= x && x < n);
        return parents[find(x)];
    }
 
    vector<vector<int>> groups() {
        vector<int> parent_id(n), group_size(n);
        for (int i = 0; i < n; i++) {
            parent_id[i] = find(i);
            group_size[parent_id[i]]++;
        }
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[parent_id[i]].push_back(i);
        }
        result.erase(
            remove_if(result.begin(), result.end(),
            [&](const vector<int>& v) { return v.empty(); }),
            result.end()
        );
        return result;
    }
};

using DSU = DisjointSet;
