// class Solution {
// public:
//     int firstUniqChar(string s) {
//        vector<int> arr(26,0);
//         for( char c:s){
//             arr[c-'a']++;
//         }
//         for(int i=0;i<s.length();i++){
//             if(arr[s[i]-'a']==1) return i;
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int firstUniqChar(std::string s) {
        vector<int> count(26, 0);
        queue<pair<char, int>> q;

        // Step 1: Count the frequency of each character and maintain the queue
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            count[c - 'a']++;
            q.push({c, i});
        }

        // Step 2: Find the first unique character
        while (!q.empty()) {
            auto front = q.front();
            char c = front.first;
            int index = front.second;

            if (count[c - 'a'] == 1) {
                return index;
            } else {
                q.pop();
            }
        }

        return -1;
    }
};