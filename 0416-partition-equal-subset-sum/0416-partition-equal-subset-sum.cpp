#define ll long long
class Solution {
public:
    int ifpossible(int n, int W, vector<int>&nums, vector<vector<int>> &dp){
        if(n==0 || W==0) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        int num= nums[n-1];
        if(num<=W){
            int ans1= num+ ifpossible(n-1,W-num,nums,dp);
            int ans2= ifpossible(n-1,W,nums,dp);

            return dp[n][W] = max(ans1, ans2);
        }
        else{
            return dp[n][W]= ifpossible(n-1,W, nums,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2!=0) return false;
        int target= sum/2;
        vector<vector<int>>dp(nums.size()+1, vector<int>(target+1,-1));
        return target == ifpossible(nums.size(), target, nums,dp);
    }
};