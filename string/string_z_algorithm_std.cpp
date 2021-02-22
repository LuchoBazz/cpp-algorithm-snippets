// z_array=length of the longest substring starting from s[i] which is also a prefix of s
vector<int> z_algorithm(const string &s) {
    int n = (int) s.size();
    vector<int> z_array(n);
    int left=0, right=0;
    z_array[0] = 0;
    for(int idx = 1; idx < n; ++idx) {
        if(idx > right) {
            left = right = idx;
            while(right < n && s[right-left] == s[right])
                right++;
            z_array[idx] = right - left;
            right--;
        } else {
            int k = idx-left;
            if(z_array[k] < right-idx+1) {
                z_array[idx] = z_array[k];
            } else {
                left = idx;
                while(right < n && s[right-left] == s[right])
                    right++;
                z_array[idx] = right - left;
                right--;
            }
        }
    }
    return z_array;
}
