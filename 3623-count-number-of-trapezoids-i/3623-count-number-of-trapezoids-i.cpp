class Solution {
public:
    int m= 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(vector<int>p : points){
            mp[p[1]]++;
        }
        long long ans = 0;
        long long prevlines = 0;
        for(auto&it : mp){
            int count = it.second;
            long long lines = 1LL*count*(count-1)/2;
            ans += (lines*prevlines)%m;
            prevlines += lines;
        }
        return ans%m;
    }
};
