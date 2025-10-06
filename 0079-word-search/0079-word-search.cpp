class Solution {
public:
    int dx[4]= {-1, 0, 1, 0};
    int dy[4]= {0, 1, 0,-1};
    
    bool solve(vector<vector<char>>& board, string &word,int indx, int i, int j,int m , int n,vector<vector<bool>>&visited){
        if(indx == word.length()) return true;

        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]) return false;
        if(word[indx] != board[i][j]){
            return false;
        }

        visited[i][j]= true;
        for(int k=0;k<4;k++){
            int ni= i+dx[k];
            int nj= j+dy[k];
            if(solve(board, word, indx+1, ni, nj , m ,n,visited)){
                return true;
            }
        }
        visited[i][j]= false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]== word[0]){
                    vector<vector<bool>>visited(m,vector<bool>(n,false));
                    if(solve(board, word,0, i, j, m, n, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};