
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        vector<char> temp;
        int max = 0;
        for (char ch : s) {
            auto it =find(temp.begin(), temp.end(), ch);
            if (it != temp.end()) {
                temp.size()>max?max=temp.size():max=max;
                temp.erase(temp.begin(), it + 1); 
            }
            temp.push_back(ch);
        }
        temp.size()>max?max=temp.size():max=max;
        return max;
    }
};