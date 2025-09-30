class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num: nums){
            mp[num]++;
        }
        int ans=0;
        for(auto [val, freq]: mp){
            if(mp.count(val+1)){
                ans= max(ans, freq+mp[val+1]);
            }
        }
        return ans;
    }
};