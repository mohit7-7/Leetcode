class Solution {
public:
    bool check(vector<int>&nums, int size, int d){
        vector<long long>suffix(size, 0);
        suffix[size-1]= nums[size-1];
        for(int i=size-2; i>=0;i--){
            suffix[i]= nums[i]+ suffix[i+1];
        }
        long long pre = 0;
        for(int i=0;i<size;i++){
            if(i%d==0) {
                if(pre == suffix[i]) return true;
            }
            pre += nums[i];
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>h1d(m*n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                h1d[i*n+j] = grid[i][j];
            }
        }
        int size= m*n;
        if(check(h1d, size, n)) return true;
        vector<int>v1d(m*n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v1d[j*m+i] = grid[i][j];
            }
        }
        if(check(v1d,size, m)) return true;
        return false;
    }
};