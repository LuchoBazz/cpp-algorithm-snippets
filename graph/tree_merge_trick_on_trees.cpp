// Reference: https://usaco.guide/plat/merging?lang=cpp
const int mxN = 2e5 + 10;
vector<int> adj[mxN];
int colors[mxN];
set<int> cnt[mxN];
int answer[mxN];
 
void dfs(int node, int parent) { // O(n*lg^2(n))
    cnt[node].insert(colors[node]);
 
    for(auto &child: adj[node]) {
        if(child == parent) continue;

        dfs(child, node);

        // always make the child set the smallest
        if(cnt[child].size() > cnt[node].size())
            swap(cnt[child], cnt[node]); // O(1)

        for(auto &it: cnt[child]) {
            cnt[node].insert(it);
        }
        cnt[child].clear(); // if time is too high don't use, use when giving MLE
    }
    answer[node] = (int) cnt[node].size();
}
// dfs(0, -1)