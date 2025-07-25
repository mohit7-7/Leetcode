class Solution {
public:
    bool dfscycle(int node, vector<bool>&visited, vector<vector<int>>&adjlist, vector<bool>&inrec, stack<int>&st){
        visited[node]= true;
        inrec[node]= true;
        for(auto &neighbour: adjlist[node]){
            if(visited[neighbour] && inrec[neighbour])
                return true;
            if(!visited[neighbour]){
                if(dfscycle(neighbour,visited, adjlist ,inrec, st))
                    return true;
            }
        }
        inrec[node]= false;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjlist(n);
        for(auto & edge:edges){
            int u=edge[0], v= edge[1];
            adjlist[v].push_back(u);
        }

        vector<bool> visited(n,false);
        vector<bool> inrec(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfscycle(i, visited, adjlist, inrec, st))
                    return {};
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};