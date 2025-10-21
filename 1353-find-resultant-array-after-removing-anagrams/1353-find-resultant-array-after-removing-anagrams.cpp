class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;

        auto check = [](string&s1, string&s2){
            vector<int>freq(26,0);
            for(char ch: s1){
                freq[ch-'a']++;
            }

            for(char ch: s2){
                freq[ch-'a']--;
            }

            return any_of(freq.begin(), freq.end(), [](int x){return x==0;});
        };
        ans.push_back(words[0]);
        for(auto& string : words){
            if(!check(string, ans.back())){
                ans.push_back(string);
            }
        }
        return ans;
    }
};