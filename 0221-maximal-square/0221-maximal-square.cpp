class Solution {
public:
    int solve(int i , int j, vector<vector<char>>&matrix, vector<vector<int>>&dp, int &maxi){
        if(i>= matrix.size() || j>= matrix[0].size()){
            return 0;
        }

        if(dp[i][j]!= -1) return dp[i][j];

        int right= solve(i, j+1,matrix, dp, maxi);
        int down= solve( i+1, j, matrix, dp, maxi);
        int diagonal= solve(i+1, j+1, matrix, dp, maxi);
        if(matrix[i][j]=='1'){
            dp[i][j]= 1+ min({right,down, diagonal});
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows= matrix.size();
        int cols= matrix[0].size();
        vector<vector<int>>dp(rows, vector<int>(cols,-1));
        int maxi=0;
        solve(0,0, matrix,dp, maxi);
        return maxi*maxi;
    }
};