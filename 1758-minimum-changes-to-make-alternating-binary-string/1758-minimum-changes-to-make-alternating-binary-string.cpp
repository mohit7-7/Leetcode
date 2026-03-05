class Solution {
public:
    int minOperations(string s) {
        int n= s.length();
        int op1 =0 , op2= 0;
        for(int i=0;i<n;i++){
            char dig = (i%2)?'1':'0';
            if( s[i] != dig ) op1++;
            dig = (i%2)?'0':'1';
            if (s[i]!= dig) op2++; 
        }
        return min(op1, op2);
    }
};