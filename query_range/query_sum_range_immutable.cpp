template<typename T>
class QuerySum {
public:
 
    vector<T> dp;
 
    QuerySum(vector<T>& nums) {
        if(int(nums.size()) == 0) return;
        dp.resize(int(nums.size()) + 1);
        dp[0] = 0;
        for(int i = 1; i <= int(nums.size()); ++i) {
            dp[i] = dp[i-1] + nums[i-1];
        }
    }
    
    T sum(int left, int right) {
        return dp[right+1] - dp[left];
    }
};