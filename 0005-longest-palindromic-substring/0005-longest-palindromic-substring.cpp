class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
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
