class Solution {
public:
    int dp[1001][1001];
    bool check(int i, int j, string s){
        if(dp[i][j]!=-1) return dp[i][j];
        int l= i, h= j;
        while(l<h){
            if(s[l++]!=s[h--]) return dp[i][j]= 0;
        }
        return dp[i][j]=1;
    }
    int countSubstrings(string s) {
        int n= s.length();
        memset(dp,-1,sizeof(dp));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};
