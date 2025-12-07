class Solution {
    public int countOdds(int low, int high) {
        int count = 0;

        if (low % 2 != 0 && high % 2 != 0) {
            return (int) Math.floor((double)(high - low - 1) / 2) + 2;
        }
        else if (low % 2 == 0 && high % 2 == 0) {
            return (int) Math.ceil((double)(high - low - 1) / 2);
        }
        else {
            return (high - low - 1) / 2 + 1;
        }
    }
}
