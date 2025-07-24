class Solution {
public:
    string robotWithString(string s) {
        int n= s.size();
        vector<char> nextsmaller(n);
        nextsmaller[n-1]= s[n-1];
        for(int i=n-2;i>=0;i--){
            nextsmaller[i]= min(s[i], nextsmaller[i+1]);
        }
        string t="",  p="";
        for(int i=0;i<s.size();i++){
            t.push_back(s[i]);
            char minchar= (i+1< n) ? nextsmaller[i+1] : s[i];

            while(!t.empty() && t.back() <= minchar){
                p+= t.back();
                t.pop_back();
            }
        }

        while(!t.empty()){
            p+= t.back();
            t.pop_back();
        }
        return p;
    }
};