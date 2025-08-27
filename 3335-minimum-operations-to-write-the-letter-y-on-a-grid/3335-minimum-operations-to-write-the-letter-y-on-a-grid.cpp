class Solution {
public:
    int makey(int Yuse, int Xuse, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int steps=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i<m/2) &&  (i==j) ){
                    if(grid[i][j]!= Yuse)
                        steps++;
                }
                else if((i<m/2) && ((i+j)==n-1)){
                    if(grid[i][j]!= Yuse)
                        steps++;
                }
                else if((i>=m/2) && (j==(n/2))){
                    if(grid[i][j]!= Yuse)
                        steps++;
                }
                else{
                    if(grid[i][j]!= Xuse) steps++;
                }
            }
        }
        return steps;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        return min({makey(0,1,grid), makey(1,0,grid),
                    makey(0,2,grid), makey(1,2,grid),
                    makey(2,0,grid), makey(2,1,grid)});
    }
};