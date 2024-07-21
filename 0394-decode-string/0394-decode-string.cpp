// class Solution {
// public:
//     string decodeString(string s) {
//         stack<int> number;
//         stack<string> str;
//         string currentstring="";
//         int currentnum= 0;
//         string ans="";
//         for(char ch:s){
//             if(isdigit(ch)){
//                 currentnum = currentnum*10 + (ch-'0');
//             }
//             else if(ch=='['){
//                 number.push(currentnum);
//                 currentnum=0;
//                 str.push(currentstring);
//                 currentstring="";
//             }
//             else if(ch==']'){
//                 int repeatition= number.top();
//                 number.pop();
//                 string torepeat = currentstring;
//                 currentstring = str.top();
//                 while(repeatition--){
//                     currentstring+=torepeat;
//                 }
//             }
//             else{
//                 currentstring+=ch;
//             }
//         }
//          return currentstring;
//     }

// };


class Solution {
public:
    string decodeString(string s) {
        stack<int> number;        // Stack to store numbers (repetition counts)
        stack<string> str;        // Stack to store strings (contexts)
        string currentstring = ""; // Current portion of the decoded string
        int currentnum = 0;        // Current number being processed for repetition

        for (char ch : s) {
            if (isdigit(ch)) {
                // Build the number for the repetition count
                currentnum = currentnum * 10 + (ch - '0');
            } else if (ch == '[') {
                // Push the current number and string onto their respective stacks
                number.push(currentnum);
                currentnum = 0;
                str.push(currentstring);
                currentstring = "";
            } else if (ch == ']') {
                // Pop the top of the stack to get the repetition count and the previous context
                int repetition = number.top();
                number.pop();
                string torepeat = currentstring;
                currentstring = str.top();
                str.pop();
                // Repeat the decoded substring and append it to the previous context
                while (repetition--) {
                    currentstring += torepeat;
                }
            } else {
                // Append regular characters to currentstring
                currentstring += ch;
            }
        }

        return currentstring;
    }
};
