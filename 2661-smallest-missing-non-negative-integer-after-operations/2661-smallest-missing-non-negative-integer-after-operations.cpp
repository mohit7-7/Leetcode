class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(int num: nums){
            int rem =(num%value+value)%value;
            mp[rem]++;
        }

        int i=0;
        while(true){
            if(mp[i%value]>0){
                mp[i%value]--;
            }
            else{
                break;
            }
            i++;
        }
        return i;
    }
};