class Solution {
public:
    // int dpsol(int n, vector<int>&dp){ 
    //     if(n==0 || n==1) return 1;
    //     if(dp[n]!=-1)return dp[n];
    //     dp[n]= dpsol(n-1,dp)+ dpsol(n-2,dp);
    //     return dp[n];
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return dpsol(n, dp);
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    } 
};