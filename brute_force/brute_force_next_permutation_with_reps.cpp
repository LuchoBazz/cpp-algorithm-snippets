// N = len of v
// O(N^(r - l + 1) * N)
bool next_permutations_with_reps(vector<int> &v, int l, int r) {
    assert(l <= r && !v.empty());
    if (all_of(v.begin(), v.end(), [&](int x) { return x == r; }))
        return false;

    for (int i = int(v.size()) - 1; i >= 0; --i) {
        if (v[i] == r) {
            v[i] = l;
        } else {
            ++v[i];
            return true;
        }
    }
    return false;
}
// Usage:
// int n = 3, l = 1, r = 3, cnt = 1;
// vector<int> v(n, l);
// do {
//     cout << cnt++ << ") ";
//     for (auto &x : v) {
//         cout << x << ' ';
//     }
//     cout << '\n';
// } while (next_permutations_with_reps(v, l, r));

// Sample:
// n=3, l=1, r=3
// {1, 2, 3} * {1, 2, 3} * {1, 2, 3} = 3 * 3 * 3 = 27
// 1) 1 1 1 
// 2) 1 1 2 
// 3) 1 1 3 
// 4) 1 2 1 
// 5) 1 2 2 
// 6) 1 2 3 
// 7) 1 3 1 
// 8) 1 3 2 
// 9) 1 3 3 
// 10) 2 1 1 
// 11) 2 1 2 
// 12) 2 1 3 
// 13) 2 2 1 
// 14) 2 2 2 
// 15) 2 2 3 
// 16) 2 3 1 
// 17) 2 3 2 
// 18) 2 3 3 
// 19) 3 1 1 
// 20) 3 1 2 
// 21) 3 1 3 
// 22) 3 2 1 
// 23) 3 2 2 
// 24) 3 2 3 
// 25) 3 3 1 
// 26) 3 3 2 
// 27) 3 3 3