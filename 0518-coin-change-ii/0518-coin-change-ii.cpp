#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int64_t> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; ++j) {
                dp[j] += dp[j - coin];

                // Optional: clamp to avoid overflow
                if (dp[j] > INT32_MAX) dp[j] = INT32_MAX;
            }
        }

        return static_cast<int>(dp[amount]);
    }
};
