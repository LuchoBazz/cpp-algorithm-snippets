template<typename T>
class PrefixSum2D {
public:
    
    int n, m;
    vector<vector<T>> dp;
    
    PrefixSum2D()  : n(-1), m(-1) {}
    PrefixSum2D(vector<vector<T>>& grid) {
        n = (int) grid.size();
        assert(0 <= n);
        if(n == 0) { m = 0; return; }
        m = (int) grid[0].size();

        dp.resize(n+1, vector<T>(m+1, static_cast<T>(0)));
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                dp[i][j] = dp[i][j-1] + grid[i-1][j-1];

        for(int j = 1; j <= m; ++j)
            for(int i = 1; i <= n; ++i)
                dp[i][j] += dp[i-1][j];
    }
    
    T query(int x1, int y1, int x2, int y2) {
        assert(0<=x1&&x1<n && 0<=y1&&y1<m);
        assert(0<=x2&&x2<n && 0<=y2&&y2<m);
        T SA = dp[x2+1][y2+1];
        T SB = dp[x1][y2+1];
        T SC = dp[x2+1][y1];
        T SD = dp[x1][y1];
        return SA-SB-SC+SD;
    }
};