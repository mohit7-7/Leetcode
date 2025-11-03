class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost =0;
        int n= colors.size();
        vector<pair<int,int>>temp(n);
        temp.push_back(make_pair(colors[0],0));
        for(int i=1;i<n;i++){
            if(colors[i] == temp.back().first){
                if(neededTime[i]< neededTime[temp.back().second]){
                    cost += neededTime[i];
                    continue;
                }
                else {
                    cost += neededTime[temp.back().second];
                    temp.pop_back();
                }
            }
            temp.push_back({colors[i], i});
        }
        return cost;
    }
};