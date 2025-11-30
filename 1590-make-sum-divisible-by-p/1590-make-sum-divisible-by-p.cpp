class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int>ps(n+1);
        for(int i=0;i<n;i++){
            ps[i+1]= (ps[i]+ nums[i])%p;
        }

        int total= ps[n];
        int extra = total%p;
        if(extra==0) return 0;
        
        unordered_map<int, int>mp;
        int curr =0 ;
        mp[0]= -1;
        int len= n;
        for(int i=0;i<n;i++){ 
            curr= ps[i+1];
            int prev = (curr-extra+p)%p;  
            if(mp.count(prev)){
                len = min(len ,i-mp[prev]);
            }
            mp[curr]= i;
        }
        return len==n ? -1 : len;
    }
};

