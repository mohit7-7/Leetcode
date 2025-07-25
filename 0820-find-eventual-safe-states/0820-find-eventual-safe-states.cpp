class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, vector<bool>& isSafe) {
        visited[node] = true;
        pathVisited[node] = true;

        for (auto neighbour : graph[node]) {
            if (!visited[neighbour]) {
                if (!dfs(neighbour, graph, visited, pathVisited, isSafe))
                    return false;
            }
            else if (pathVisited[neighbour]) {
                return false; // cycle detected
            }
        }
        pathVisited[node] = false;
        isSafe[node] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false); // recursion stack
        vector<bool> isSafe(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, graph, visited, pathVisited, isSafe);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (isSafe[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
