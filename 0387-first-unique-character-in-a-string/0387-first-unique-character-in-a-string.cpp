class Solution {
public:
    int firstUniqChar(string s) {
       vector<int> arr(26,0);
        for( char c:s){
            arr[c-97]++;
        }
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a']==1) return i;
        }
        return -1;
    }
};