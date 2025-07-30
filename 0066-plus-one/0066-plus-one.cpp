class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        int i=n-1;
        if(digits[i]!=9){
            digits[i] = digits[i]+1;
            return digits;
        }
        else{
            while(i>0 && digits[i]==9){
                digits[i]=0;
                i--;
            }
            if(i==0 && digits[i]==9){
                digits[0]=1;
                digits.push_back(0);
                return digits;
            }
            digits[i]= digits[i]+1;
        }
        return digits;
    }
};