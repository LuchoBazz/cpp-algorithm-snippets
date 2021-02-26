vector<vector<int>> answer;
vector<int> combination;
void combinations_backtraking(const int &n, const int &k,  int idx) {
    if(idx == k) {
        answer.push_back(combination);
        return;
    }
    int start = (combination.size()==0)?1:combination.back()+1;
    for(int i = start; i <= n; ++i) {
        combination.push_back(i);
        combinations_backtraking(n, k, idx+1);    
        combination.pop_back();
    }
}