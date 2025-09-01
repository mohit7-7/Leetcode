class Solution {
public: 
    string reverseWords(string s) {
        int n= s.size();
        reverse(s.begin(), s.end());
        int i=0, j=0;
        int l=0,r=0;
        while(j<n){
            while(j<n && s[j]!=' '){
                s[r++]=s[j++];
            }
            if(l<r) {reverse(s.begin()+l , s.begin()+r);
            s[r++]=' ';
            l=r;}
            j++;
        }
        return s.substr(0,r-1);
    }
};