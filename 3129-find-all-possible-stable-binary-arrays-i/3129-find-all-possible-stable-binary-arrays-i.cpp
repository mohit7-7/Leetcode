class Solution {
public:
    int mod= 1e9+7;
    int dp[201][201][2];
    int solve(int zero,int one ,int last,int limit){
        if(zero==0 && one==0) return 1;
        if(dp[zero][one][last]!=-1) return dp[zero][one][last];
        int result =0;
        if(last ==1){
            for(int len =1 ; len<= min(limit, zero);len++){
                result = (result + solve(zero-len, one, 0,limit))%mod;
            }
        }
        if(last ==0){
            for(int len = 1; len<= min(limit ,one); len++){
                result = (result+ solve(zero, one-len , 1 , limit))%mod;
            }
        }
        return dp[zero][one][last] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp , -1 , sizeof(dp));
        int ans=0;
        if(zero>0){
            ans += solve(zero, one, 0, limit);
        }
        if(one>0){
            ans+= solve(zero, one, 1, limit);
        }
        return ans%mod;
    }
};