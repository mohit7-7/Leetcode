class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);
        int j=0;
        string temp="";
        while(j<str.length()){
            const char ch= str[j];
            int len=1;
            while(j<str.length()-1 && str[j]==str[j+1]){
                j++;
                len++;
            }
            string nottime= to_string(len);
            for(char ch:nottime){
                temp+= ch;
            }
            temp+= ch;
            j++;
        }
        return temp;
    }
};