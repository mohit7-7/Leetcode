class Solution {
    public: 
    int mod = 1e9+7;
    int numSub(string s) { 
        long long ans=0; 
        string temp=""; 
        for(char ch:s){ 
            if(ch=='0'){ 
                int l= temp.size(); 
                long long subs=  (1LL*l*(l+1)%mod);
                ans += (subs/2);
                temp=""; 
                } else{ 
                    temp+='1'; 
                } 
        } 
        long long l= temp.size();
        int subs=  (1LL*l*(l+1)%mod);
        ans += (subs/2);
        return ans%mod; 
    } 
};