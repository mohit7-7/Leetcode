class Solution {
public:
    int dp[1001];
    int solve(vector<int>&cost, int i, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int onestep = cost[i]+ solve(cost, i+1,n);
        int twostep = cost[i]+ solve(cost, i+2,n);
        return dp[i]= min(onestep, twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        memset(dp, -1, sizeof(dp));
        return min(solve(cost,0,n), solve(cost,1, n));
    }
};