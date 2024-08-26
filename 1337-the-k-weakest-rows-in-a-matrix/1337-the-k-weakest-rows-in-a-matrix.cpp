class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>sol;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size() && mat[i][j];j++){
                count++;
            }
            sol.push_back({count,i});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq(sol.begin(),sol.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};