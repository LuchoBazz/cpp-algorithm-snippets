template<typename T>
class Range {
public:
 
    vector<T> dp;
 
    Range(vector<T>& nums) {
        if(nums.size() == 0) return;
        dp.resize(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < int(nums.size()); ++i) {
            dp[i] = dp[i - 1] + nums[i];
        }
    }
    
    T sum(int i, int j) {
        if(i==0) return dp[j];
        return dp[j] - dp[i-1];
    }
};