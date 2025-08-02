class Solution {
public:
    string reverseStr(string s, int k) {
        int n= s.length();
        int i=0;
        while(i<n){
            int left=i;
            int right= min(n-1, i+k-1);
            while(left<right){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            i+= 2*k;
        }
        return s;
    }
};