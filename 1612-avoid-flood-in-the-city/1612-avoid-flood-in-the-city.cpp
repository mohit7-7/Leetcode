class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int> ans(n, 1);
        unordered_map<int,int> rainDay;
        set<int> dry;

        for (int i=0; i<n; i++) {
            if (rains[i]==0) 
                dry.insert(i);  
            else {
                int lake=rains[i];
                if (rainDay.count(lake)) {
                    int prev=rainDay[lake];
                    // find dry day after prev
                    auto it=dry.lower_bound(prev);
                    if (it==dry.end()) return {}; // no dry day available
                    int day=*it;
                    ans[day]=lake; // dry this lake on day d
                    dry.erase(*it); //  dry day used
                }
                rainDay[lake]=i;
                ans[i]=-1; // rainy day
            }
        }
        return ans;
    }
};