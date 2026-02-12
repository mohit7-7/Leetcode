class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int k = 0;
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                int val = s[j] - 'a';
                freq[val]++;
                if (freq[val] == 1)
                    k++; // new distinct character found
                maxFreq = max(maxFreq, freq[val]);

                // Check if substring [i..j] is balanced
                if (maxFreq * k == j - i + 1)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
