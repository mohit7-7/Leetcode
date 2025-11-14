class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n, vector<int>(n,0));
        for( vector<int>&q : queries ){
            int si = q[0] , sj = q[1] , endi = q[2] , endj = q[3];
            for(int i=si;i<=endi;i++){
                ans[i][sj]++;
                if(endj+1 < n){
                    ans[i][endj+1]-=1;
                }
            }
        }

        for(int i=0;i<n;i++){ 
            for(int j=1;j<n;j++){
                ans[i][j]+= ans[i][j-1];
            }
        }
        return ans;
    }
};