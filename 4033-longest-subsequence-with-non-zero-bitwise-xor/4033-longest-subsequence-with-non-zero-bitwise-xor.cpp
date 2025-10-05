class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n= nums.size();
        int xorr=0;
        for(int num:nums){
            xorr ^= num;
        }
        if(xorr) return n;
        bool flag = false;
        for(int num: nums){
            if(num!=0) flag = true;
        }
        if(!flag) return 0;
        else return n-1;
    }
};