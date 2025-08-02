class Solution {
public:
    string reverseStr(string s, int k) {
        string ans=s;
        int n= s.length();
        int i=0,j=0;
        while(j<n){
            j=i+k;
            if(j<n) reverse(ans.begin()+i, ans.begin()+j);
            else{
                reverse(ans.begin()+i, ans.end());
            }
            i+= 2*k;
        }
        return ans;
    }
};