class Solution {
public:
    void dfs(int source, int destination,vector<vector<int>>&adjlist, vector<bool>&visited, vector<vector<int>>&ans,        vector<int>&path){ 
        if(source==destination){
            ans.push_back(path);
            return;
        }
        visited[source]= true;
        for(auto &neighbour: adjlist[source]){
            if(!visited[neighbour]){
                path.push_back(neighbour);
                dfs(neighbour,destination,adjlist,visited, ans,path);
                path.pop_back();
            }
        }
        visited[source]= false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>>ans;
        vector<bool>visited(n,false);
        vector<int>path;
        path.push_back(0);
        dfs(0,n-1,graph,visited,ans,path);
        return ans;
    }
};