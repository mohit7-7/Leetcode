class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }

        int count=0;
        for(int i=0;i<words.size();i++){
            string curr = words[i];
            int latest=-1;
            for(int j=0;j<curr.size();j++){
                auto it= upper_bound(mp[curr[j]].begin(), mp[curr[j]].end(),latest);
                if(it==mp[curr[j]].end())break;
                latest= *it;
                if(j==curr.size()-1) count++;
            }
        }
        return count;
    }
};