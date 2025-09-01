class Solution {
public:
    int mod= 1e9+7;
    int solve(int i, int j, vector<vector<int>>& grid, int dir,             vector<vector<vector<int>>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        if(grid[i][j]==1){
            if(dir==0){
                return dp[i][j][dir]=solve(i-1,j,grid,1,dp);
            }
            else{
                return dp[i][j][dir]= solve(i,j-1,grid,0,dp);
            }
        }
        int left = solve(i,j-1,grid,0,dp)%mod;
        int up = solve(i-1,j,grid,1,dp)%mod;
        return dp[i][j][dir]= (up +left)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(m-1,n-1,grid,0,dp);
        //0 - left;
        //1 - up
    }
};