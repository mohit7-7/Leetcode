class Solution {
public:
    long long flowerGame(int n, int m) {
        // if(n==1 && m==1) return 0;
        long long totalodd= n- (n/2);
        long long totalodd2= m- (m/2);
        return totalodd *(m/2)+ totalodd2*(n/2);

    }
};