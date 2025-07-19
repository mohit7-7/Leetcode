class Solution {
public:
    unordered_set<string> st;
    bool check(string s){
        string tocheck="";
        for(int i=0;i<s.size();i++){
            tocheck += s[i];
            if(s[i+1]=='/'&& st.count(tocheck)){
                return false;
            }
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        for(string s: folder){
            if(check(s)){
                st.insert(s);
            }
        }
        vector<string>ans(st.begin(), st.end());
        return ans;
    }
};