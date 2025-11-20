
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        vector<char> temp;
        int maxi = 0;

        for (char ch : s) {
            auto it =find(temp.begin(), temp.end(), ch);
            if (it != temp.end()) {
                maxi = max(maxi, static_cast<int>(temp.size()));
                temp.erase(temp.begin(), it + 1); 
            }
            temp.push_back(ch);
        }

        maxi =max(maxi, static_cast<int>(temp.size()));
        return maxi;
    }
};