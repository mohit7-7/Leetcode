class Solution {
public:

    bool dfs(int source , int destination , vector<list<int>>&adjlist, vector<int>&visited){
        if(source==destination) return true;
        visited[source]= true;
        for(auto &neighbour: adjlist[source]){
            if(!visited[neighbour]){
                if(dfs(neighbour,destination,adjlist, visited))
                    return true;
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<list<int>>adjlist(n);
        for(auto edge:edges){
            int u= edge[0];
            int v= edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        // --------------------------------------DFS CODE-------------------------------------------//

        vector<int> visited(n,false);
        return dfs(source, destination,adjlist, visited);
        

        //---------------------------------------BFS CODE------------------------------------------//
        // queue<int>q;
        // vector<int> visited(n,false);
        // q.push(source);
        // visited[source]= true;
        // while(!q.empty()){
        //     int node= q.front();
        //     if (node == destination) return true;
        //     q.pop();
        //     for(auto &neighbour: adjlist[node]){
        //         if(!visited[neighbour]){
        //             visited[neighbour]= true;
        //             q.push(neighbour);
        //         }
        //     }
        // }
        // return false;
    }
};