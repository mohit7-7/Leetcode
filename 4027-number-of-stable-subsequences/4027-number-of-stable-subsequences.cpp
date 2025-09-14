class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(vector<int>&nums, int indx, int ne, int no){
        if(ne > 2 || no >2) return 0;
        if(indx<0) return 1;
        if(dp[indx][ne][no]!=-1) return dp[indx][ne][no];
        if(nums[indx]%2==0){
            return dp[indx][ne][no] = solve(nums, indx-1, ne+1, 0)%mod + solve(nums, indx-1,ne, no)%mod;
        }
        else{
            return dp[indx][ne][no]=solve(nums, indx-1, 0, no+1)%mod+ solve(nums,indx-1, ne, no)%mod;
        }
    }
    int countStableSubsequences(vector<int>& nums) {
        int n= nums.size();
        dp.assign(n,vector<vector<int>>(4,vector<int>(4,-1)));
        if(n<3) return (1<<n)-1;
        return solve(nums,n-1, 0,0)%mod -1;   
    }
};