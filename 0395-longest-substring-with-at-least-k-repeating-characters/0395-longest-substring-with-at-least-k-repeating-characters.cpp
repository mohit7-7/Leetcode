class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        int n = s.size();

        // Try 1 to 26 unique characters
        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int unique = 0;         // total unique chars in window
            int countAtLeastK = 0;  // kitne chars ki freq >= k hai

            while (right < n) {
                if (unique <= uniqueTarget) {
                    int idx = s[right] - 'a';
                    if (freq[idx] == 0) unique++; // naye char mila
                    freq[idx]++;
                    if (freq[idx] == k) countAtLeastK++; // freq ab k ho gaya
                    right++;
                } else {
                    int idx = s[left] - 'a';
                    if (freq[idx] == k) countAtLeastK--; // freq ab k se kam ho gaya
                    freq[idx]--;
                    if (freq[idx] == 0) unique--; // ek char hat gaya
                    left++;
                }

                // Agar saare unique chars ki freq >= k hai
                if (unique == uniqueTarget && unique == countAtLeastK) {
                    maxLen = max(maxLen, right - left);
                }
            }
        }

        return maxLen;
    }
};
