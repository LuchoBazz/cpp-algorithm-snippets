// string_hashing_static_compress

template <typename T>
vector<int> rabin_karp(const T &text, const T &pattern) {
    int n = (int) text.size();
    int m = (int) pattern.size();
    hashing<string> txt(text);
    hashing<string> pat(pattern);
    vector<int> occurrences;
    for(int i = 0; i < n-m+1; ++i){
        auto hash_pat = pat.query(0, m-1);
        auto hash_txt = txt.query(i, i+m-1);
        if(hash_pat == hash_txt)
            occurrences.push_back(i);
    }
    return occurrences;
}

template <typename T>
vector<int> search_pattern(const T &text, const T &pattern) {
    return rabin_karp(text, pattern);
}
// Rabin-Karp
// Time Complexity: O(N), Space Complexity: O(N)
// N: Length of text
// Usage:
//   string txt = "ABABABAB"; 
//   string pat = "ABA";  
//   vector<int> ans = search_pattern(txt, pat); {0, 2, 4}
