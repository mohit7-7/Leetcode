class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> suffixY(n + 1, 0);
        vector<int> prefixN(n + 1, 0);

        // Build suffixY (count of 'Y' after index i)
        for (int i = n - 1; i >= 0; i--) {
            suffixY[i] = suffixY[i + 1] + (customers[i] == 'Y');
        }

        // Build prefixN (count of 'N' before index i)
        for (int i = 0; i < n; i++) {
            prefixN[i + 1] = prefixN[i] + (customers[i] == 'N');
        }

        int minPenalty = INT_MAX, bestHour = 0;

        // Try closing at each hour i (0..n)
        for (int i = 0; i <= n; i++) {
            int penalty = prefixN[i] + suffixY[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i;
            }
        }
        return bestHour;
    }
};
