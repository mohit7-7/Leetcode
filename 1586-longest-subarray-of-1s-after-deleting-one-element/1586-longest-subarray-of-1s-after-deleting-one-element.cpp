class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeroCount = 0, maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeroCount++;
            
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            
            // subtract 1 because we need to delete one element
            maxLen = max(maxLen, right - left);
        }
        
        return maxLen;
    }
};
