class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n, vector<int>(n,0));
        for( vector<int>&query : queries ){
            int starti= query[0], startj= query[1], endi= query[2], endj= query[3];
            for(int i=starti; i<=endi; i++){
                for(int j=startj; j<=endj;j++){
                    ans[i][j]++;
                }
            }
        }
        return ans;
    }
};