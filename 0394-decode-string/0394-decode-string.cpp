class Solution {
public:
    string decodeString(string s) {
        stack<int> number;
        stack<string> str;
        string currentstring="";
        int currentnum= 0;
        for(char ch:s){
            if(isdigit(ch)){
                currentnum = currentnum*10 + (ch-'0');
            }
            else if(ch=='['){
                number.push(currentnum);
                currentnum=0;
                str.push(currentstring);
                currentstring="";
            }
            else if(ch==']'){
                int repeatition= number.top();
                number.pop();
                string torepeat = currentstring;
                currentstring = str.top();
                str.pop();
                while(repeatition--){
                    currentstring+=torepeat;
                }
            }
            else{
                currentstring+=ch;
            }
        }
         return currentstring;
    }

};