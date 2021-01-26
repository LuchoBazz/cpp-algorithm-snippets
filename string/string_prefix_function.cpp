
template <typename T>
vector<int> prefix_function(const T &s) {
    int n = (int) s.size();
    vector<int> lcp(n, 0);
    lcp[0] = 0;
    int matched = 0;
    for(int pos = 1; pos < n; ++pos){
        while(matched > 0 && s[pos] != s[matched])
            matched = lcp[matched-1];
        if(s[pos] == s[matched])
            matched++;
        lcp[pos] = matched;
    }
    return lcp;
}
// Longest prefix which is also suffix
// Time Complexity: O(N), Space Complexity: O(N)
// N: Length of pattern