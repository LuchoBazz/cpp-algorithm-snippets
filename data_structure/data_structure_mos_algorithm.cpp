struct query {
    int left, right, index;
    query (int l, int r, int idx)
        : left(l), right(r), index(idx) {}
};

int S; // S = sqrt(n);

bool cmp (query a, query b) {
    if (a.left/S != b.left/S)
        return a.left/S < b.left/S;
    return a.right > b.right;
}

// global functions
void add(int idx) {

}
void del(int idx) {

}
int get_ans() {

}

// at main()
vector<query> Q;
Q.reserve(q+1);
int from, to;
for(int i = 0; i < q; ++i){
    in >> from >> to;
    Q.push_back(query(from, to, i));
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
    
    ans[Q[i].index] = get_ans();
}
