class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n= nums.size();
        int count =0;
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<n ;i++){
            int j = upper_bound(nums.begin(), nums.end(), nums[i])-nums.begin();
            int greater = n-j;
            if(greater >= k) count++;
        }
        return count;
    }
};