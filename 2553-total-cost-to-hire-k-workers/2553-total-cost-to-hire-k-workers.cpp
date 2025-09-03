class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> left, right;
        int i = 0, j = n - 1;

        for (; i < candidates && i <= j; i++) {
            left.push({costs[i], i});
        }

        for (int cnt = 0; cnt < candidates && j >= i; cnt++, j--) {
            right.push({costs[j], j});
        }

        while (k--) {

            pair<int,int> l = left.empty() ? make_pair(INT_MAX, -1) : left.top();
            pair<int,int> r = right.empty() ? make_pair(INT_MAX, -1) : right.top();

            if (l.first <= r.first) {
                ans += l.first;
                left.pop();
                if (i <= j) {
                    left.push({costs[i], i});
                    i++;
                }
            } else {
                ans += r.first;
                right.pop();
                if (i <= j) {
                    right.push({costs[j], j});
                    j--;
                }
            }
        }

        return ans;
    }
};
