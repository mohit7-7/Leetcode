class Solution {
public:
    int t[301][5001];
    int solve(int amount, vector<int>&coins, int i){
        if(amount==0) return 1;
        if(i<0) return 0;
        if(t[i][amount]!=-1) return t[i][amount];
        int ans= 0;
        if( coins[i] <= amount){
            ans += solve(amount-coins[i], coins, i);
        }
        ans += solve(amount, coins, i-1);
        return t[i][amount]= ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        int ans =0;
        int n= coins.size();
        ans = solve(amount, coins,n-1);
        return ans;
    }
};