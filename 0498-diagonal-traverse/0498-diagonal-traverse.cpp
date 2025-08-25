class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m= mat.size(), n= mat[0].size();
        map<int, vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        bool toreverse= true;
        vector<int>ans;
        for(int i=0;i<mp.size();i++){
            vector<int>temp= mp[i];
            if(toreverse){
                reverse(temp.begin(), temp.end());
            }
            for(int no: temp){
                ans.push_back(no);
            }  
            toreverse= !toreverse;
        }
        return ans;
    }
};