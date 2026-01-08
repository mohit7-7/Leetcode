class Solution {
public:
    int solve(vector<int>&nums , int l , int r){
        int prev2=0, prev1=0;
        for(int i=l;i<=r;i++){
            int pick= nums[i]+ prev2;
            int notpick = prev1;
            int curr = max(pick , notpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        return solve(nums, 0 , n-1);
    }
};