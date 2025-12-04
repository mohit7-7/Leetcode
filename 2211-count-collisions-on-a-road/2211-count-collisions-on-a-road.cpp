class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        // ignore left movers at left edge
        while (i < n && s[i] == 'L') i++;

        // ignore right movers at right edge
        while (j >= 0 && s[j] == 'R') j--;

        int ans = 0;

        // count all R or L in the middle
        for (int k = i; k <= j; k++) {
            if (s[k] != 'S') ans++;
        }
        return ans;
    }
};
