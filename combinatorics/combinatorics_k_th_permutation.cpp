vector<int> kth_permutation(vector<int> perm, int  k) {
    int64_t factorial = 1LL;
    int n = (int) perm.size();
    for(int64_t num = 2; num < n; ++num)
        factorial *= num; // (n-1)!
    k--; // k-th to 0-indexed
    vector<int> answer; answer.reserve(n);
    while(true) {
        answer.push_back(perm[k / factorial]);
        perm.erase(perm.begin()+(k/factorial));
        if((int) perm.size() == 0)
            break;
        k %= factorial;
        factorial /= (int) perm.size();
    }
    return answer;
}

vector<int> kth_permutation(int n, int k, int start=0) {
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), start);
    return kth_permutation(perm, k);
}

string kth_perm_string(int n, int k) {
    assert(1 <= n && n <= 26);
    vector<int> perm = kth_permutation(n, k);
    string alpha = "";
    for(char i='a'; i <= ('a'+n); ++i)
        alpha.push_back(i);
    string answer="";
    for(int &idx: perm)
        answer.push_back(alpha[idx]);
    return answer;
}