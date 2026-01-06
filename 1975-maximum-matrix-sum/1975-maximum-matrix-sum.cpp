class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int neg =0;
        long long int sum = 0;
        int smallest = INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0) neg++;
                smallest = min(smallest , abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        return (neg%2==0)? sum : sum- 2*smallest;
    }
};