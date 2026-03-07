class Solution {
public:

    string makePattern(char start, int len) {
        string p;

        for(int i = 0; i < len; i++){
            p += start;
            start = (start == '0') ? '1' : '0';
        }

        return p;
    }

    int minFlips(string s) {
        int n = s.size();

        int match0 = 0, match1 = 0;
        int ans = INT_MAX;

        string p0 = makePattern('0', 2*n);
        string p1 = makePattern('1', 2*n);

        for(int i = 0; i < n; i++){
            match0 += (s[i] == p0[i]);
            match1 += (s[i] == p1[i]);
        }

        ans = min(n - match0, n - match1);

        for(int i = 0; i < n; i++){

            match0 -= (s[i] == p0[i]);
            match1 -= (s[i] == p1[i]);

            match0 += (s[(i+n)%n] == p0[i+n]);
            match1 += (s[(i+n)%n] == p1[i+n]);

            ans = min(ans, min(n - match0, n - match1));
        }

        return ans;
    }
};