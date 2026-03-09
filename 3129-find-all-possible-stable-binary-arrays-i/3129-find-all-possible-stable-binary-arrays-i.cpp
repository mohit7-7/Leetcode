class Solution {
public:
    int mod = 1e9+7;
    int dp[202][202][2][202];
    int z,o,l;

    int solve(int ones , int zeroes, int last, int streak){
        if(ones ==0 && zeroes==0) return 1;
        int &res = dp[ones][zeroes][last][streak];
        if(res!=-1) return res;
        long long ans =0;
        if(zeroes>0){
            if(last ==0){
                if(streak< l)
                    ans += solve(ones, zeroes-1, 0, streak+1);
            }
            else{
                ans += solve(ones ,zeroes-1, 0,1);
            }
        }

        if(ones>0){
            if(last==1){
                if(streak<l){
                    ans += solve(ones-1, zeroes, 1, streak+1);
                }
            }
            else{
                ans += solve(ones-1 , zeroes, 1, 1);
            }
        }
        return res=ans%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        z = zero, o = one , l = limit;
        memset(dp,-1,sizeof(dp));
        long long ans =0;

        if(z>0){
            ans += solve(o, z-1, 0, 1);
        }
        if(o>0){
            ans += solve(o-1, z, 1, 1);
        }
        return ans%mod;
    }
};