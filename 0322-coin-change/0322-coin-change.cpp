class Solution {
public:
    int t[13][10001];
    int solve(vector<int>&coins, int amount, int i){
        if(amount ==0) return 0;
        if(i<0) return 1e9;
        if(t[i][amount]!=-1) return t[i][amount];
        int ans1= INT_MAX;
        if(coins[i]<= amount){
            ans1 = 1+solve(coins, amount-coins[i], i);
        } 
        int ans2 = solve(coins , amount , i-1);
        return t[i][amount]=min(ans1, ans2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        memset(t,-1,sizeof(t));
        int ans=  solve(coins , amount, n-1);
        if(ans < 1e9) return ans ;
        else return -1;
    }
};