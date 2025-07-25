class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> mst(n,false);
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            int curr = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if(!mst[curr]){
                mst[curr]= true;
                ans+= cost;
                for(int v=0;v<n;v++){
                    if(curr!= v){
                        int wt= abs(points[curr][0]- points[v][0])+ abs(points[curr][1]- points[v][1]);
                        pq.push({wt,v});
                    }
                }
            }
        }
        return ans;
    }
};