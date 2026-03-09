class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        unordered_map<int,int>mp;
        int indx=0;
        for(int i = 0; i < capacity.size(); i++){
            if(!mp.count(capacity[i])){
                mp[capacity[i]] = i;
            }
        }
        sort(capacity.begin(), capacity.end());
        int ansi = lower_bound(capacity.begin() , capacity.end(), itemSize)-capacity.begin();
        if(ansi == capacity.size()) return -1;
        int ans= capacity[ansi];
        return mp[ans];
    }
};