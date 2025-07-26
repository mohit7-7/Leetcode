class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        if(n==0) return 0;
        int maxians = INT_MIN;
        int i=0, j=0;
        unordered_map<int,int> mp;
        while(j<n){
            while(mp[s[j]]){
                mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
            j++;
            maxians= max(maxians,j-i);
        }
        return maxians;
    }
};