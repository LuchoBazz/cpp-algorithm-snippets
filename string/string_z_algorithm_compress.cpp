// z_array=length of the longest substring starting from s[i] which is also a
// prefix of s
vector<int> z_algorithm(const string &s) {
    int n = (int)s.size();
    vector<int> z_array(n);
    int left = 0, right = 0;
    z_array[0] = 0;
    for (int idx = 1; idx < n; ++idx) {
        z_array[idx] = max(0, min(z_array[idx - left], right - idx + 1));
        while (idx + z_array[idx] < n &&
               s[z_array[idx]] == s[idx + z_array[idx]]) {
            left = idx;
            right = idx + z_array[idx];
            z_array[idx]++;
        }
    }
    return z_array;
}
