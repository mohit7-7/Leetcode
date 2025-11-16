class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(string &s, int l, int r) {
        if(dp[l][r]!=-1) return dp[l][r];
        while (l < r) {
            if(dp[l][r]!=-1) return dp[l][r];
            if (s[l] != s[r]) return dp[l][r]= false;
            l++, r--;
        }
        return dp[l][r]=true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int maxLen = 0, start = 0;   
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
