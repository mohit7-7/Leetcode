class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> row, col;
        // Group buildings by row and column
        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];
            row[y].insert(x);
            col[x].insert(y);
        }

        int ans = 0;

        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            auto &r = row[y];
            auto &c = col[x];

            // row checks
            auto it = r.find(x);
            bool left  = (it != r.begin());
            bool right = (next(it) != r.end());

            // column checks
            auto it2 = c.find(y);
            bool down = (it2 != c.begin());
            bool up   = (next(it2) != c.end());

            if (left && right && up && down) ans++;
        }

        return ans;
    }
};
