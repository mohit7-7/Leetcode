class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {

        // xor of a subarray[l ... r] is 0 when prefixor[l-1]== prefixxor[r]; 
        int  n= nums.size();
        if(n==1) return 0;
        int len = 0;
        int co=0 , ce=0;
        int xorr=0;
        map<pair<int,int>, int>mp;
        mp[{0,0}]= -1;
        int i=0;
        for(int num : nums){
            if(num%2) co++;
            else ce++;
            xorr ^= num;

            int diff = co- ce;
            pair<int, int>key = {xorr, diff};
            if(mp.count(key)){
                len = max(len, i-mp[key]);
            }
            else{
                mp[key]= i;
            }
            i++;
        }
        return len;
        
    }
};