class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n= nums.size();
        int count =0;
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<n ;i++){
            int j = upper_bound(nums.begin(), nums.end(), nums[i])-nums.begin();
            int greater;
            if(i==j) greater= n-1-j;
            else greater = n-j;
            if(greater >= k) count++;
        }
        return count;
    }
};