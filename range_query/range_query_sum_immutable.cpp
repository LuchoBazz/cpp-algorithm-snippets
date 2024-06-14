template <typename T> class PrefixSum {
  public:
    int n;
    vector<T> dp;

    PrefixSum() : n(-1) {}
    PrefixSum(vector<T> &nums) {
        n = (int)nums.size();
        if (n == 0)
            return;
        dp.resize(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i - 1] + nums[i - 1];
    }

    T query(int left, int right) {
        assert(0 <= left && left <= right && right <= n - 1);
        return dp[right + 1] - dp[left];
    }
};
