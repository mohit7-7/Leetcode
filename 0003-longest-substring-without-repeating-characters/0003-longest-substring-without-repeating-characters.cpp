class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        int maxians = INT_MIN;
        int i=0, j=0;
        unordered_map<int,int> mp;
        while(j<n){
            while(mp[s[j]]){
                mp.erase(s[i]);
                i++;
            }
            mp[s[j]]++;
            j++;
            maxians= max(maxians, static_cast<int>(mp.size()));
        }
        return maxians;
    }
};