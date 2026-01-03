class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>t;
    string states[12] = {"RYG", "RGY","RYR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG","RGR"};
    int solve(int n , int previndx){
        if(n==0) return 1;
        if(t[n][previndx]!=-1) return t[n][previndx];
        int result =0;
        string prev = states[previndx];
        for(int i=0;i<12;i++){
            if(i== previndx) continue;
            string curr = states[i];
            bool flag= false;
            for(int x=0;x<3;x++){
                if(prev[x]== curr[x]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                result = (result+solve(n-1,i))%mod;
            }
        }
        return t[n][previndx] = result;
    }
    int numOfWays(int n) {
        t.resize(n,vector<int>(12,-1));
        int result = 0;
        for(int i=0;i<12;i++){
            result = (result+ solve(n-1,i))%mod;
        }
        return result;
    }
};