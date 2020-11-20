// string_lps

template <typename T>
vector<int> search_kmp(const T &txt, const T &pat) {
    vector<int> output;
    int N = txt.size();
    int M = pat.size();
    if(M > N) return output;
    int j = 0; // index for pat[] 
    // Calculate the vector with the data from the 'Longest Prefix Suffix'
    vector<int> lps = LPS(pat); 
    int i = 0; // index for txt[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++;i++; 
        }
        if (j == M) {
            // Found pattern at index (i-j)
            output.push_back(i-j);
            j = lps[j - 1]; 
        } else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i = i + 1; 
            }
        } 
    }
    return output;
}
//KMP - Knuth-Morris-Pratt algorithm 
// Time Complexity: O(N), Space Complexity: O(N)
// N: Length of text
// Usage:
//   string txt = "ABABABAB"; 
//   string pat = "ABA";  
//   vector<int> ans = search_kmp(txt, pat); {0, 2, 4}