class Solution {
public:
    int dx[4]= {-1,0,1,0};
    int dy[4]= {0,-1,0,1};

    bool possible(vector<vector<int>>&grid, int mid, int i , int j, int n, vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=n || j>=n || visited[i][j] || grid[i][j]> mid) return false;
        visited[i][j]= true;
        if(i==n-1 && j==n-1) return true;

        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(possible(grid, mid, ni, nj,n, visited)){
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        int low= grid[0][0];
        int high= (n*n-1);

        int result= 0;
        while(low<=high){
            int mid= (low+high)/2;
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            if(possible(grid, mid,0,0,n,visited)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};