class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, last = INT_MIN;

        for (int num : nums) {
            int left = num - k;
            int right = num + k;
            // pick the smallest possible value > last
            int placed = max(left, last + 1);
            if (placed <= right) {
                ans++;
                last = placed;
            }
        }
        return ans;
    }
};


