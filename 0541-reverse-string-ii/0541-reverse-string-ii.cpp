class Solution {
public:
    string reverseStr(string s, int k) {
        int n= s.length();
        int i=0,j=0;
        while(j<n){
            j=i+k;
            if(j<n) reverse(s.begin()+i, s.begin()+j);
            else{
                reverse(s.begin()+i, s.end());
            }
            i+= 2*k;
        }
        return s;
    }
};