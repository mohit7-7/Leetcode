class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_set<string>st;
        unordered_set<string>final;
        for(int i=0;i+9<n;i++){
            string tocheck= s.substr(i,10);
            if(st.count(tocheck)){
                final.insert(tocheck);
            }
            else{
                st.insert(tocheck);
            }
        }
        vector<string>ans;
        for (auto it = final.begin(); it != final.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};