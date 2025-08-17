class Solution {
public:

    // string generate(string word){
    //     vector<int>frequency(26,0);
    //     for(char &ch:word){
    //         frequency[ch-'a']++;
    //     }

    //     string sortedword="";
    //     for(int i=0;i<26;i++){
    //         int freq= frequency[i];
    //         if(freq>0){
    //             sortedword += string(freq,i+'a');
    //         }
    //     }
    //     return sortedword;
    // }
    string generate(string word){
        sort(word.begin(), word.end());
        return word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string x:strs){
            string word= x;
            string newword= generate(word);
            mp[newword].push_back(x);
        }

        vector<vector<string>>result;
        for(auto &it: mp){
            result.push_back(it.second);
        }
        return result;
    }
};