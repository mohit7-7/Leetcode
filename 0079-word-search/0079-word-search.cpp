class Solution {
public:
    vector<vector<int>> directions= { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int m,n;
    bool solve(int i, int j, vector<vector<char>> & board, int indx, string word){
        if(indx == word.length())  return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$' ) return false;
        if( board[i][j]!= word[indx]) return false;  
        char temp= board[i][j];
        board[i][j]='$';

        for(int k=0;k<4;k++){
            int new_i= i+directions[k][0];
            int new_j= j+directions[k][1];
            if(solve(new_i, new_j, board, indx+1, word)){
                return true;
            }
        }
        board[i][j]= temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m= board.size();
        n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]== word[0]  && solve(i,j, board,0, word)){
                    return true;
                }
            }
        }
        return false;
    }
};