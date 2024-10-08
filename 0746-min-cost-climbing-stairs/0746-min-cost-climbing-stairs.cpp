class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int>dp(n+1);
        dp[0]= 0;
        dp[1]= cost[0];
        dp[2]= cost[1];
        for(int i=2;i<n;i++){
            dp[i+1]= min(dp[i],dp[i-1])+ cost[i];
        }
        return min(dp[n],dp[n-1]);
    }
};