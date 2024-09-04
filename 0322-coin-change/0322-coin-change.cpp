class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<amount+1;j++){
                dp[j]= min(dp[j-coins[i]]+1,dp[j]); 
            }
        }
        return dp[amount]==amount+1 ? -1: dp[amount];
    }
};