// Complexity: O(|N+Q|*sqrt(|N|)*|add+del|)

struct Query {
    int left, right, index;
    Query (int l, int r, int idx)
        : left(l), right(r), index(idx) {}
};

int S; // S = sqrt(n);

bool cmp (const Query &a, const Query &b) {
    if (a.left/S != b.left/S)
        return a.left/S < b.left/S;
    return a.right > b.right;
}

// global functions
void add(int idx) {

}
void del(int idx) {

}
auto get_answer() {

}

// at main()
vector<Query> Q;
Q.reserve(q+1);
int from, to;
for(int i = 0; i < q; ++i){
    in >> from >> to; // don't forget (from--, to--) if it's 1-indexed
    Q.push_back(Query(from, to, i));
}

S = sqrt(n); // n = size of array
sort(Q.begin(), Q.end(), cmp);

vector<int> ans(q);
int left = 0, right = -1;

for (int i = 0; i < (int) Q.size(); ++i) {
    while (right < Q[i].right)
        add(++right);
    while (left > Q[i].left)
        add(--left);
    while (right > Q[i].right)
        del(right--);
    while (left < Q[i].left)
        del(left++);
    
    ans[Q[i].index] = get_answer();
}
