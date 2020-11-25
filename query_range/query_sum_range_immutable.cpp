template<typename T>
class QuerySum {
public:
    
    int n;
    vector<T> dp;
 
    QuerySum(vector<T>& nums) {
        n = int(nums.size());
        if(n == 0) return;
        dp.resize(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] + nums[i-1];
        }
    }
    
    T sum(int left, int right) {
        assert(0 <= left && left <= right && right <= n - 1);
        return dp[right+1] - dp[left];
    }
};