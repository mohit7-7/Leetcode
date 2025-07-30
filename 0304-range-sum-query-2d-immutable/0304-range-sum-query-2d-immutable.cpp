class NumMatrix {
public:
    vector<vector<int>>nummatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        nummatrix.resize(n,vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nummatrix[i][j] = matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                nummatrix[i][j] = nummatrix[i][j-1]+matrix[i][j];
            }
        }

        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                nummatrix[i][j] += nummatrix[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r=0,s=0,t=0;
        if(col1-1>=0){
            r= nummatrix[row2][col1-1];
        }
        if(row1-1>=0){
            s= nummatrix[row1-1][col2];
        }
        if(row1-1>=0 && col1-1>=0){
            t= nummatrix[row1-1][col1-1];
        }
        return nummatrix[row2][col2]-r-s+t;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */