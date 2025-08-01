class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        queue<int>q;
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]= 0;  //0 --> blue .. 10 --> red..
                q.push(i);
                while(!q.empty()){
                    int node= q.front();
                    q.pop();
                    for(auto neighbour: graph[node]){
                        if(color[neighbour]!=-1 && color[neighbour] == color[node])
                            return false;
                        if(color[neighbour]==-1){
                            q.push(neighbour);
                            color[neighbour]= !color[node];
                        }
                    }
                }
            }
        }
        return true;    
        
    }
};