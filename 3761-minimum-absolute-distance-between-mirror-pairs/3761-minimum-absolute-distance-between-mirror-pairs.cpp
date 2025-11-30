class Solution {
public:
    int rev(int num){
        int  r = 0;
        while(num){
            int temp = num%10;
            r = r*10+temp;
            num/=10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mp;
        int i=0;
        int ans= n+1;
        for(int num : nums){
            if(mp.count(num)){
                ans = min(ans, i-mp[num]);
            }
            mp[rev(num)]=i;
            i++;
        }
        return ans==n+1 ? -1 : ans;
    }
};