class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int mod=1e9+7;
        int m=grid.size(),n=grid[0].size();
        vector<pair<long long,long long>> dp(n);
        dp[0].first=dp[0].second=grid[0][0];

        for(int j=1;j<n;++j)
        dp[j].first=dp[j].second=grid[0][j]*dp[j-1].first;


        for(int i=1;i<m;++i)
        {
            dp[0].first=dp[0].second=dp[0].first*grid[i][0];
            for(int j=1;j<n;++j)
            {
                long long up_min = dp[j].first;
                long long up_max = dp[j].second;
                long long left_min = dp[j-1].first;
                long long left_max = dp[j-1].second;
                long long val = grid[i][j];
                
                dp[j].first = min({up_min * val, up_max * val, left_min * val, left_max * val});
                dp[j].second = max({up_min * val, up_max * val, left_min * val, left_max * val});
            }
        }
        return dp[n-1].second>=0?(dp[n-1].second%mod):-1;
        }
};