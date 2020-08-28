template <typename T>
vector<int> LPS(const T &pat) { 
    int M = pat.size();
    vector<int> lps(M);
    int len = 0; 
    int i = 1; 
    lps[0] = 0; // lps[0] is always 0
    // Calculate lps[i] for i = 1 to M-1
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } else { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } else { 
                lps[i] = len; i++; 
            } 
        } 
    }
    return lps;
}
// Time Complexity: O(N), Space Complexity: O(N)
// N: Length of pattern