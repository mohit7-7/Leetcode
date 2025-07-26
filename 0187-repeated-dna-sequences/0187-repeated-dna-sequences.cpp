class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        string tocheck;
        for(int i=0;i+9<n;i++){
            tocheck= s.substr(i,10);
            mp[tocheck]++;
        }
        vector<string>ans;
        for (auto[stringg, freq]: mp) {
            if(freq>1){
                ans.push_back(stringg);
            }
        }
        return ans;
    }
};