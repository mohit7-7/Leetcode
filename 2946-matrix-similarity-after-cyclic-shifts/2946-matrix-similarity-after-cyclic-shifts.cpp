class Solution {
public:
    bool check(vector<int>& arr , int row, int k){
        int n= arr.size();
        if(row%2){
            for(int i=0;i<n;i++){
                int indx = (i+k)%n;
                if(arr[indx]!= arr[i]) return false;
            }
        }
        else{
            for(int i=0;i<n;i++){
                int indx = (i-k)%n;
                if(indx <0 ) indx += n;
                if(arr[indx]!= arr[i]) return false;
            }
        }
        return true;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        for(int i=0;i<m;i++){
            if(!check(mat[i], i, k)) return false;
        }
        return true;
    }
};