class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxlen=0;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-1;i>0;i--){
            int val=nums[i]-1;
            int lb= lower_bound(nums.begin(), nums.end(),val)-nums.begin();
            if(nums[lb]==val){
                maxlen= max(maxlen, i-lb+1);
            }
        }
        return maxlen;
    }
};