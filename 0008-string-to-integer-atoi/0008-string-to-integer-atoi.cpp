#include <string>
#include <vector>
#include <limits>

class Solution {
public:
    int myAtoi(std::string s) {
        std::vector<int> temp;
        bool status = true;
        bool signEncountered = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ' && !signEncountered) {
                continue;
            }
            
            if ((s[i] == '+' || s[i] == '-') && !signEncountered) {
                status = (s[i] == '+');
                signEncountered = true;
                continue;
            }
            
            if (s[i] >= '0' && s[i] <= '9') {
                temp.push_back(s[i] - '0');
                signEncountered = true;
            } else {
                break;
            }
        }

        long long ans = 0;

        for (int i = 0; i < temp.size(); ++i) {
            ans = ans * 10 + temp[i];
            if (ans > INT_MAX && status) {
                return INT_MAX;
            } else if (-ans < INT_MIN && !status) {
                return INT_MIN;
            }
        }

        return status ? ans : -ans;
    }
};
