class Solution {
public:
    int candy(vector<int>& nums) {
        int n= nums.size();
        if(n<=1) return n;
        int ans= 0;
        vector<int>candy(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]> nums[i-1]){
                candy[i]= candy[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]> nums[i+1]){
                candy[i]= max(candy[i], candy[i+1]+1);
            }
        }
        ans= accumulate(candy.begin(), candy.end(),0);
        return ans;
    }
};