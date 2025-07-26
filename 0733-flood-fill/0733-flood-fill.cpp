class Solution {
public:
    void dfs(vector<vector<int>>&image, int row, int col, int oldcolor, int newcolor, vector<vector<int>>&visited, int n , int m){
        visited[row][col] = true;
        image[row][col] = newcolor;

        if(row+1 < n && !visited[row+1][col] && image[row+1][col] == oldcolor)
            dfs(image, row+1, col, oldcolor, newcolor, visited, n, m);
        if(row-1>=0 && !visited[row-1][col] && image[row-1][col] == oldcolor)
            dfs(image, row-1, col, oldcolor, newcolor, visited, n, m);
        if(col+1 < m && !visited[row][col+1] && image[row][col+1] == oldcolor)
            dfs(image, row, col+1, oldcolor, newcolor, visited, n, m);
        if(col-1 >=0 && !visited[row][col-1] && image[row][col-1] == oldcolor)
            dfs(image, row, col-1, oldcolor, newcolor, visited, n, m);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size(), m= image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        dfs(image, sr,  sc, image[sr][sc] ,color, visited, n , m);
        return image;
    }
};