class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n= nums.size();
        int l=0, r=0;
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        while(r<n){
            int val = nums[r];
            while(mp.count(val)){
                mp.erase(nums[l]);
                sum-= nums[l];
                l++;
            }
            mp[val]= r;
            sum+=val;
            ans= max(ans,sum);
            r++;
        }
        return ans;
    }
};