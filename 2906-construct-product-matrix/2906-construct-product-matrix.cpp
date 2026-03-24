class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mod = 12345;

        int size = m * n;
        vector<long long> flat(size);

        // flatten matrix
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                flat[i*n + j] = grid[i][j];
            }
        }

        vector<long long> prefix(size, 1), suffix(size, 1);

        // prefix
        for(int i = 1; i < size; i++) {
            prefix[i] = (prefix[i-1] * flat[i-1]) % mod;
        }

        // suffix
        for(int i = size-2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * flat[i+1]) % mod;
        }

        // result
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < size; i++) {
            long long val = (prefix[i] * suffix[i]) % mod;
            ans[i/n][i%n] = (int)val;
        }

        return ans;
    }
};