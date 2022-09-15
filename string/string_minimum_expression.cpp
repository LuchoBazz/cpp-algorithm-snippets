// Given a string, s returns the index where the lexicographically minimal rotation of s begins.
// O(n)
int minimum_expression(string s) {
    s = s+s; // if not concatenated it returns the minimum suffix index
    int len = s.size(), i = 0, j = 1, k = 0;
    while (i+k < len && j+k < len) {
        if (s[i+k] == s[j+k]) k++;
        else if (s[i+k] > s[j+k]) i = i+k+1, k = 0; // change to < for maximum
        else j = j+k+1, k = 0;
        if (i == j) j++;
    }
    return min(i, j);
}
// Usage:
// int idx = minimum_expression(s);
// s += s;
// cout << s.substr(idx, n); 