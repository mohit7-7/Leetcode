class Solution {
public:
    int mod= 1e9+7;
    int numberOfWays(int target, int x) {
        vector<int>poss;
        for(int i=1;target>=pow(i,x);i++){
            poss.push_back(pow(i,x));
        }
        int n= poss.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int take=0;
                if(poss[i-1]<= j){
                    take= dp[i-1][j-poss[i-1]];
                }
                int nottake = dp[i-1][j];
                dp[i][j]= (take+nottake)%mod;
            }
        }
        return dp[n][target]%mod;
    }
};