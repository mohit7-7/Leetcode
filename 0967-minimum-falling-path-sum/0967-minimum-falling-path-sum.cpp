class Solution {
public:
    int solve(int i, int j ,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int m = matrix[0].size(), n= matrix.size();
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up= matrix[i][j]+ solve(i-1,j,matrix,dp);
        int leftdiag= matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int rightdiag= matrix[i][j]+solve(i-1,j+1,matrix,dp);
        return dp[i][j]= min({up, leftdiag, rightdiag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans= INT_MAX;
        int n= matrix.size(), m= matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // for(int j=0;j<n;j++){
        //     ans= min(ans, solve(n-1,j,matrix,dp));
        // }

        for(int j=0;j<n;j++){
            dp[0][j]= matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up= matrix[i][j]+ dp[i-1][j];
                int leftdiag= 1e9;
                if(j>0) leftdiag= matrix[i][j]+ dp[i-1][j-1];
                int rightdiag= 1e9;
                if(j<m-1) rightdiag = matrix[i][j]+ dp[i-1][j+1];
                dp[i][j]= min({up, leftdiag, rightdiag});
            }
        }

        for(int j=0;j<m;j++){
            ans= min(ans, dp[n-1][j]);
        }
        return ans;
    }
};