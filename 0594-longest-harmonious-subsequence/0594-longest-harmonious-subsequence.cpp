class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mp;
        for(int num: nums){
            mp[num]++;
        }

        int ans=0;
        for(int num: nums){
            if(mp.count(num+1)){
                ans= max(ans , mp[num]+mp[num+1]);
            }
        }
        return ans;
    }
};