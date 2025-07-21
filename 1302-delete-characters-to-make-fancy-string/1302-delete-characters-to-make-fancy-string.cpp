class Solution {
public:
    string makeFancyString(string s) {
        string result;
        for (char c : s) {
            int sz = result.size();
            if (sz >= 2 && result[sz - 1] == c && result[sz - 2] == c)
                continue;
            result.push_back(c);
        }
        return result;
    }
};
