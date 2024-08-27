class Solution {
public:
    int dpsol(int n, vector<int>&dp){ 
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1)return dp[n];
        dp[n]= dpsol(n-1,dp)+ dpsol(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dpsol(n, dp);
    } 
};