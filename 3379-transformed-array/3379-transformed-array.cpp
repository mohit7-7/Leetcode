class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                int indx = (i+nums[i])%n;
                ans[i]= nums[indx];
            }
            else{
                int indx = (i-abs(nums[i])+n)%n;
                ans[i]= nums[indx];
            }
        }
        return ans;
    }
};