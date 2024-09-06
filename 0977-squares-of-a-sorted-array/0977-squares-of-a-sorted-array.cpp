class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int i=nums.size()-1;
        int low=0, high= nums.size()-1;
        while(low<=high){
            int lowsq= nums[low]*nums[low];
            int highsq= nums[high]*nums[high];
            if(lowsq > highsq){
                ans[i--]=lowsq;
                low++;
            }
            else{
                ans[i--]=highsq;
                high--;
            }
        }
        return ans;
    }
};

