class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int i=nums.size()-1;
        int low=0, high= nums.size()-1;
        while(low<=high){
            if((nums[low]*nums[low]) > (nums[high]*nums[high])){
                ans[i--]=nums[low]*nums[low];
                low++;
            }
            else{
                ans[i--]=nums[high]*nums[high];
                high--;
            }
        }
        return ans;
    }
};

