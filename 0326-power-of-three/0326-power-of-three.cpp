class Solution {
public:
    static bool isPowerOfThree(int n) {
        return (n==1)?true:((n<=0 || n%3)?false:isPowerOfThree(n/3));
    }
};