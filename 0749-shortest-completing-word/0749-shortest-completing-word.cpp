class Solution {
public:

    bool check(string word,unordered_map<char, int>mp){
        for(char ch:word){
            int word= tolower(ch);
            if(mp.count(word)){
                mp[word]--;
                if(mp[word]==0) mp.erase(word);
            }
        }
        if(mp.size()==0) return true;
        return false;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int>mp;
        for(char ch: licensePlate){
            ch= tolower(ch);
            if(ch >='a' && ch <='z'){
                mp[ch]++;
            }
        }
        string ans;
        for(int i=0;i<words.size();i++){
            if(check(words[i],mp)){
                if(words[i].size()<ans.size() || ans==""){
                    ans= words[i];
                }
            }
        }
        return ans;
    }
};