class Solution {
public:
    int solve(vector<int>&nums, int currindx, int prev , vector<vector<int>>&t){
        if(currindx == nums.size()) return 0;
        if(t[currindx][prev+1]!=-1) return t[currindx][prev+1];
        int len= 0;
        int take=0;

        if(prev==-1 || nums[currindx]> nums[prev]){
            take = 1+solve(nums, currindx+1, currindx,t);
        }
        int nottake = solve(nums, currindx+1,prev,t);
        len = max(take,nottake);
        return t[currindx][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>t(n,vector<int>(n+1,-1));
        return solve(nums, 0, -1, t);
    }
};