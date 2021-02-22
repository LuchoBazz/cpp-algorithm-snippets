// Complexity: O(n^min(k,n-k))
ool next_combination(vector<int> &comb, int n) {
    int k = (int) comb.size();
    for (int i = k - 1; i >= 0; i--) {
        if (comb[i] <= n - k + i) {
            ++comb[i];
            while (++i < k) {
                comb[i] = comb[i - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

void all_combinations(int n, int k) {
    vector<int> comb(k);
    iota(comb.begin(), comb.end(), 1);
    do {
        for (const int &v : comb) {
            cout << v << " ";
        }
        cout << endl;
    } while (next_combination(comb, n));
}

// Generate all combinations using backtracking

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