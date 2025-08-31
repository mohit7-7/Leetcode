class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        int x= (log2(n)/ log2(4));
        return pow(4,x)==n;
    }
};