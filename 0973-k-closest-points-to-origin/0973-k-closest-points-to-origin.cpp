class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        vector<pair<int,int>>temp;
        for(int i=0;i<points.size();i++){
            int distsq=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            temp.push_back({distsq,i});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq(temp.begin(),temp.end());
        for(int i=0;i<k;i++){
            int idx= pq.top().second;
            pq.pop();
            ans.push_back(points[idx]);
        }
        return ans;
    }
};