class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int i=0,j=0;
        while(j<n){
            if(nums[j]!=0 && nums[i]==0){
                swap(nums[j],nums[i]);
            }
            if(nums[i]!=0)i++;
            j++;
        }
    }
};