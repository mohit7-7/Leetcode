class Solution {
public:
    int dp[1001][1001];
    int solve(int i , int j, string&s1, string &s2){
        if(i<=0 || j<=0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]){
            dp[i][j]= solve(i-1, j-1, s1,s2)+ s1[i-1];
        }
        else{
            dp[i][j]= max(solve(i-1, j, s1, s2), solve(i, j-1, s1,s2));
        }
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int totalascii =0;
        for(char ch:s1) {
            totalascii += ch;
        }
        for(char ch:s2){
            totalascii += ch;
        }
        int n= s1.size(), m= s2.size();
        int minascii = solve(n, m, s1, s2);
        return totalascii- 2*minascii;
    }
};