class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, INT_MAX-1);
        minCoins[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
                }
                else{
                    minCoins[i]= minCoins[i];
                }
            }
        }

        return minCoins[amount] != INT_MAX-1? minCoins[amount] : -1;        
    }
};