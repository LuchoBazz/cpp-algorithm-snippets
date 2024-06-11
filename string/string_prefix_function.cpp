template <typename T> vector<int> prefix_function(const T &s) {
    int n = (int)s.size();
    vector<int> lps(n, 0);
    lps[0] = 0;
    int matched = 0;
    for (int pos = 1; pos < n; ++pos) {
        while (matched > 0 && s[pos] != s[matched])
            matched = lps[matched - 1];
        if (s[pos] == s[matched])
            matched++;
        lps[pos] = matched;
    }
    return lps;
}
// Longest prefix which is also suffix
// Time Complexity: O(N), Space Complexity: O(N)
// N: Length of pattern
