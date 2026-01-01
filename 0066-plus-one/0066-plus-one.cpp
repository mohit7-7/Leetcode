class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1; i>=0; i--){
            digits[i]++;
            if(digits[i]!=10){
                return digits;
            }
            digits[i]=0;
        }
        vector<int> temp(digits.size()+1,0);
        temp[0]=1;
        return temp;
    }
};