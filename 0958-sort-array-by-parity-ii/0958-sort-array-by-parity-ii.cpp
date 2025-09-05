class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n= nums.size();
        int even =0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0 && i%2!=0){
                swap(nums[i], nums[even]);
                even+=2;
                i--;
                continue;
            }
        }
        return nums;
    }
};
