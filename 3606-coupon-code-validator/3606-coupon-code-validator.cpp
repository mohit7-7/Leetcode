class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string,string>>temp;
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(isActive[i] && code[i]!="" && (businessLine[i]== "electronics"||businessLine[i]== "grocery" || businessLine[i]==
            "pharmacy" || businessLine[i]=="restaurant")){
                bool flag = true;
                for(char ch: code[i]){
                    if(!(isalnum(ch)|| ch=='_')){
                        flag  = false;
                    }
                }
                if(flag) temp.push_back({businessLine[i],code[i]});
            }
        }
        sort(temp.begin(), temp.end());

        for(auto& tem : temp){
            ans.push_back(tem.second);
        }
        return ans;
    }
};