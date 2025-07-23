class Solution {
public:

int removepattern(string &s, char a, char b, int val) {
        stack<char> st;
        int gain = 0;

        for (char ch : s) {
            if (!st.empty() && st.top() == a && ch == b) {
                st.pop();      
                gain += val;    
            } else {
                st.push(ch);
            }
        }

        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return gain;
    }

    int maximumGain(string s, int x, int y) {
        int sum=0;
        if(x>y){
            sum+= removepattern(s,'a','b',x);
            sum+= removepattern(s,'b','a',y);
        }
        else{
            sum+= removepattern(s,'b','a',y);
            sum+= removepattern(s,'a','b',x);
        }
        return sum;
    }
};