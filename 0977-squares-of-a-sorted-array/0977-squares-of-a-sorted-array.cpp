class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            nums[i]*= nums[i];
        }
        int i=nums.size()-1;
        int low=0, high= nums.size()-1;
        while(low<=high){
            if(nums[low]>nums[high]){
                ans[i--]=nums[low++];
            }
            else{
                ans[i--]=nums[high--];
            }
        }
        return ans;
    }
};

