class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        if(value==1) return nums.size();
        unordered_map<int,int>mp;
        for(int num: nums){
            int rem= (num%value+ value)% value;
            mp[rem]++;
        }
        int i=0;
        while(true){
            int rem = i%value;
            if(mp[rem]==0) break;
            mp[rem]--;
            i++;
        }
        return i;
    }
};