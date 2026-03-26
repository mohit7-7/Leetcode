#define ll long long
class Solution {
public:
    bool hcheck(vector<vector<int>>&grid, ll totalsum){
        int m = grid.size() , n= grid[0].size();
        ll topsum =0;
        unordered_set<ll>st;
        for(int i=0;i<=m-2;i++){
            for(int j=0;j<n;j++){
                st.insert(grid[i][j]);
                topsum += grid[i][j];
            }
            ll bottomsum = totalsum - topsum;
            ll diff = topsum-bottomsum;
            if(diff ==0) return true;
            if(diff == (ll)grid[0][0] || diff == (ll)grid[0][n-1]) return true;
            if(diff == (ll)grid[i][0]) return true;
            if(i>0 && n>1 && st.count(diff)) return true;
        }
        return false;
    }

    void reverse(vector<vector<int>>&grid){
        int m = grid.size();
        int start =0 , end= m-1;
        while(start <= end){
            swap(grid[start++], grid[end--]);
        }
    }

    void transpose(vector<vector<int>>&grid){
        int m = grid.size() , n= grid[0].size();
        vector<vector<int>> temp(n , vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[j][i] = grid[i][j];
            }
        }
        grid = temp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll totalsum =0;
        int m = grid.size(), n= grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                totalsum += grid[i][j];
            }
        }
        if(hcheck(grid, totalsum )) return true;
        reverse(grid);
        if(hcheck(grid, totalsum )) return true;
        reverse(grid);
        transpose(grid);
        if(hcheck(grid, totalsum )) return true;
        reverse(grid);
        if(hcheck(grid, totalsum)) return true;
        return false;
    }
};