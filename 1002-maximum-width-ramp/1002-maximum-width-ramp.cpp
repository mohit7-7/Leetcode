class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        // Step 2: Traverse from right and find max width ramp
        int maxWidth = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                maxWidth = max(maxWidth, j - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};
