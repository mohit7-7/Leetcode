class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(string & word : words){
            int val=0;
            for(char &ch : word){
                val+= weights[ch-'a'];
            }
            val = val%26;
            val = (25-val)<0 ? (25-val+25): (25-val);
            ans+= val+'a';
        }
        return ans;
    }
};
