class Solution {
public:

    void makenew(string &s){
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+= (s[i]+1%26);
        }
        s+= temp;
    }
    char kthCharacter(int k) {
        string org= "a";
        while(org.size()<k){
            makenew(org);
        }
        return org[k-1];
    }
};