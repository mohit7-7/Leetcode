class Solution {
public:
    int count;
    int dfs(int node, int parent , int k , vector<vector<int>>&adjlist, vector<int>&values){
        int sum = values[node];

        for(auto &neighbour : adjlist[node]){
            if(neighbour != parent){
                sum += dfs(neighbour, node , k , adjlist , values);
                sum %=k;
            }
        }
        sum %=k;
        if(sum ==0) count++;
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adjlist(n);
        for(auto &edge: edges){
            int u= edge[0], v= edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        count =0;
        dfs(0, -1, k, adjlist, values);
        return count;

    }
};