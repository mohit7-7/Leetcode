class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int>ans;
        if (time == 0){
            for(int i=0;i<n;i++) ans.push_back(i);
            return ans;
        }
        if (2 * time >= n) return {};

        vector<int> nonInc(n, 0), nonDec(n, 0);

        // Compute non-increasing streaks (left to right)
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1])
                nonInc[i] = nonInc[i - 1] + 1;
        }

        // Compute non-decreasing streaks (right to left)
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1])
                nonDec[i] = nonDec[i + 1] + 1;
        }

        // Check for good days
        for (int i = time; i < n - time; i++) {
            if (nonInc[i] >= time && nonDec[i] >= time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
