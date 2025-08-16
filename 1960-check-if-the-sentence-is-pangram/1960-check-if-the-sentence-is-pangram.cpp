class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>freq(26,0);
        for(char ch:sentence) freq[ch-'a']= true;
        for(int i=0;i<26;i++){
            if(freq[i]==false) return false;
        }
        return true;
    } 
};