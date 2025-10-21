class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int minus=0 , plus= 0;
        for(auto &op : operations){
            if(op[1]=='-') minus ++;
            else plus++;
        }
        return 0-minus+plus;
    }
};