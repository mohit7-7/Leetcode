class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> poss={"999", "888", "777", "666","555","444","333","222","111","000"};
        for(auto &st:poss){
            if(num.find(st)!= string::npos){
                return st;
            }
        }
        return "";
    }
};