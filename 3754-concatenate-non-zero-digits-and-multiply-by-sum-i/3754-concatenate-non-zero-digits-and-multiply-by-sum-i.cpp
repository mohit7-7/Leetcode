class Solution {
public:
    long long sumAndMultiply(int n) {
        string temp ="";
        string num = to_string(n);
        int sum=0;
        for(char ch: num){
            if(ch!='0')
                temp += ch;
            sum += ch-'0';
        }

        long long number=0;
        for(char ch: temp){
            number = number*10 + (ch-'0');
        }
        return 1LL*number*sum;

    }
};