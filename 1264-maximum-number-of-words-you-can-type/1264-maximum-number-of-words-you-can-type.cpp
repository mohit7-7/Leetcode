class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        for(int i=0;i<text.size();i++){
            char ch= text[i];
            if(st.find(ch)!= st.end()){
                while(i<text.size() && text[i]!=' ') i++;
            }
            else if(ch==' ' || i== text.size()-1)count++;
        }
        return count;
    }
};