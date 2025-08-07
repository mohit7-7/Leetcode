class Solution {
public:
    int mincoins(int n, int amount, vector<vector<int>>& dp, vector<int>& coins) {
        if (n == 0) return (amount == 0) ? 0 : 1e9;

        if (dp[n][amount] != -1) return dp[n][amount];

        if (coins[n - 1] <= amount) {
            int include = 1 + mincoins(n, amount - coins[n - 1], dp, coins);
            int exclude = mincoins(n - 1, amount, dp, coins);
            return dp[n][amount] = min(include, exclude);
        } else {
            return dp[n][amount] = mincoins(n - 1, amount, dp, coins);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = mincoins(n, amount, dp, coins);
        return (ans >= 1e9) ? -1 : ans;
    }
};
