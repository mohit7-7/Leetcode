class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        int dx[]= {-1,0,1,0};
        int dy[]= {0,-1,0,1};
        while(!q.empty()){
            int row= q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row1 = row+dx[i];
                int col1 = col+dy[i];
                if(row1>=0 && col1>=0 && row1<n && col1<m && mat[row1][col1]==1){
                    ans[row1][col1]=ans[row][col]+1;
                    mat[row1][col1]=0;
                    q.push({row1,col1});
                }
            }
        }
        return ans;
    }
};