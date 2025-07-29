class Solution {
public:     
    int n,m;
    void dfs(int i, int j,vector<vector<int>>& board, vector<vector<bool>>& visited, int &count){
        visited[i][j]=1;
        count--;
        int dx[]= {-1,0,1,0};
        int dy[]= {0,-1,0,1};
        for(int x=0;x<4;x++){
            int newi= i+dx[x];
            int newj= j+dy[x];
            if(newi>=0 && newi<n && newj>=0 && newj<m && board[newi][newj]==1 && !visited[newi][newj]){
                dfs(newi, newj, board, visited,count);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        n= board.size();
        m= board[0].size();
        int count1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    count1++;
                }
            }
        }
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            //first col
            if(board[i][0]==1 && !visited[i][0]){
                dfs(i,0,board,visited,count1);
            }
            
            //last col
            if(board[i][m-1]==1 && !visited[i][m-1]){
                dfs(i,m-1,board,visited,count1);
            }
        }
        for(int j=0;j<m;j++){
            //first row
            if(board[0][j]==1 && !visited[0][j]){
                dfs(0,j,board,visited,count1);
            }

            //last row
            if(board[n-1][j]==1 && !visited[n-1][j]){
                dfs(n-1,j,board,visited,count1);
            }
        }
        return count1;
    }
};