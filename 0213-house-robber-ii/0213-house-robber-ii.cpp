class Solution {
public:
    int hr1(vector<int>& nums){
        int n= nums.size();
        vector<int>dp(n+1,0);
        dp[1]= nums[0];
        for(int i=1;i<n;i++){
            dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        vector<int> temp;
        vector<int> temp1;
        int n= nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp.push_back(nums[i]);
        }
        return max(hr1(temp), hr1(temp1));
    }
};