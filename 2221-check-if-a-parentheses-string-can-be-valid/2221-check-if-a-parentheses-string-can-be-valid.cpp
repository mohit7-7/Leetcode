class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2!=0) return false;
        int open=0,free=0;
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0'){
                free++;
            }
            else if(s[i]=='('){
                open++;
            }
            else{
                open--;
            }
            if(open+free<0) return false;
        }
        int close=0;
        free=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
                free++;
            }
            else if(s[i]==')'){
                close++;
            }
            else{
                close--;
            }
            
            if(close+free<0) return false;
        }
        return true;
    }
};