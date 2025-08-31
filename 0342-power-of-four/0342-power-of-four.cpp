class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        int x= (log10(n)/ log10(4));
        return pow(4,x)==n;
    }
};