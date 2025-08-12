class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(int target, int x) {
        vector<int> poss;
        for (int i = 1; ; i++) {
            long long p = 1;
            for (int k = 0; k < x; k++) p *= i;
            if (p > target) break;
            poss.push_back((int)p);
        }

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int p : poss) {
            for (int j = target; j >= p; j--) {
                dp[j] = (dp[j] + dp[j - p]) % mod;
            }
        }
        return dp[target];
    }
};
