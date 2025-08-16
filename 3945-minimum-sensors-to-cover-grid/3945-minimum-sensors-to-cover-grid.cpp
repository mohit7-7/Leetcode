class Solution {
public:
    int minSensors(int n, int m, int k) {
        int step = 2 * k + 1;  
        int row = ceil((double)n/step);
        int col = ceil((double)m/step);
        return row * col;
    }
};
