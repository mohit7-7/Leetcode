class Solution {
public:
    int m , n;

    int findmin(int i, int j, vector<vector<int>>& grid, int k) {
        vector<int> vals;

        // collect elements
        for(int row = i; row < i + k; row++) {
            for(int col = j; col < j + k; col++) {
                vals.push_back(grid[row][col]);
            }
        }

        // sort them
        sort(vals.begin(), vals.end());

        int ans = INT_MAX;
        // find minimum absolute difference between DISTINCT values
        for(int x = 1; x < vals.size(); x++) {
            if(vals[x] != vals[x-1]) {
                ans = min(ans, vals[x] - vals[x-1]);
            }
        }

        return (ans == INT_MAX ? 0 : ans);
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>ans (m-k+1, vector<int>(n-k+1,0));
        for(int i=0;i<m;i++){
            if(i+k >m) break;
            for(int j=0; j<n;j++){
                if(j+k >n ) break;
                int mini = findmin(i, j, grid, k);
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};