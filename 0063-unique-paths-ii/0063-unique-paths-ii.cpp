class Solution {
public:
    int solve(int i, int j ,vector<vector<int>>& obstacle,vector<vector<int>>&dp ){
        if(i==0 && j==0 && obstacle[i][j]!=1) return 1;
        if(i<0 || j<0) return 0;
        if(obstacle[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(i-1,j,obstacle,dp);
        int left= solve(i, j-1,obstacle,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m= obstacle.size();
        int n= obstacle[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        return solve(m-1, n-1, obstacle,dp);
    }
};