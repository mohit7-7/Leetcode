class Solution {
public:
    int firstUniqChar(string s) {
       vector<int> arr(128);
        for( char c:s){
            arr[c]++;
        }
        for(int i=0;i<s.length();i++){
            if(arr[s[i]]==1) return i;
        }
        return -1;
    }
};