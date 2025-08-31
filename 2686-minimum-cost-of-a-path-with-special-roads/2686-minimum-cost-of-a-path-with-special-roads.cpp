class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialroads){
        // node representation= {x,y}->w
        // w is the weight to reach node x,y
        map<vector<int>, int> dist;
        dist[start]= 0;

        vector<vector<int>> newspecial;
        for(auto & road:specialroads){
            int x1 = road[0], y1= road[1];
            int x2 = road[2], y2= road[3];
            int w = road[4];
            if((abs(x2-x1)+ abs(y2-y1))>w){
                newspecial.push_back({x1,y1,x2,y2,w});
                dist[{x2,y2}]= abs(x2-start[0])+ abs(y2-start[1]);
            }
        }

        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,start[0], start[1]});
        while(!pq.empty()){
            int cost = pq.top()[0], x= pq.top()[1], y = pq.top()[2];
            pq.pop();
            for(auto &road: newspecial){
                int x1=road[0],y1= road[1],x2=road[2],y2=road[3],c=road[4];
                if(dist[{x2,y2}] > cost+ abs(x-x1)+ abs(y-y1)+ c){
                    dist[{x2,y2}]= cost+ abs(x-x1)+ abs(y-y1)+ c;
                    pq.push({dist[{x2,y2}],x2,y2});
                }
            }
        }

        
        int tx= target[0], ty= target[1];
        int mincost= abs(start[0]-tx)+ abs(start[1]-ty);
        for(auto &road: newspecial){
            int x1= road[0],y1= road[1], x2=road[2], y2= road[3], c= road[4];
            mincost = min(mincost, dist[{x2,y2}]+ abs(x2-tx)+ abs(y2-ty));
        }
        return mincost;
    }
};