class Solution {
public:
    int t[501][501][3];

    int solve(vector<vector<int>>&coins , int i , int j, int rneu){
        if(i==0 && j==0){
            if(coins[i][j]<0 && rneu>0 ) return 0;
            else{
                return coins[i][j];
            }
        }
        
        if(i<0 || j<0) return INT_MIN;
        if(t[i][j][rneu]!= INT_MIN) return t[i][j][rneu];
        int take = coins[i][j]+ max(solve(coins, i-1, j, rneu), solve(coins, i, j-1, rneu));
        int skip = INT_MIN;
        if(coins[i][j]< 0 && rneu > 0){
            skip = max(solve(coins , i-1, j , rneu-1), solve(coins , i , j-1 , rneu-1));
        }
        return t[i][j][rneu]= max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n= coins[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<3;k++){
                    t[i][j][k]= INT_MIN;
                }
            }
        }

        return solve(coins , m-1 , n-1 , 2);
    }
};