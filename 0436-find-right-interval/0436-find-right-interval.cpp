

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts(n);  // To store start points with their original indices

        for (int i = 0; i < n; i++) {
            starts[i] = {intervals[i][0], i};  // Store start point and original index
        }

        sort(starts.begin(), starts.end());  // Sort by start points

        vector<int> ans(n, -1);  // Initialize answer vector with -1

        for (int i = 0; i < n; i++) {
            int target = intervals[i][1];
            // Binary search to find the smallest start that is >= target
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (starts[mid].first >= target) {
                    ans[i] = starts[mid].second;  // Store the original index
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return ans;
    }
};
