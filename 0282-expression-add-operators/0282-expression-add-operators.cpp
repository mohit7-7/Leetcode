class Solution {
public:
    void solve(string&num ,vector<string>&ans, int target ,string temp, int indx, long long prevval, long long currval ){
        if(indx== num.size()){
            if(currval == target)
                ans.push_back(temp);
            return ;
        }

        for(int i=indx; i<num.size(); i++){
            string part = num.substr(indx,i-indx+1);
            long long val = stol(part);

            if(i!=indx && num[indx]=='0') break;
            if(indx==0) {
                solve(num, ans, target, part , i+1, val, currval+val);
            }
            else{
                solve(num, ans, target, temp+"+"+part, i+1, val, currval+val);
                solve(num, ans, target, temp+"-"+part, i+1, -val , currval-val);
                solve(num, ans, target, temp+"*"+part, i+1, prevval*val , currval - prevval + prevval*val);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        solve(num, ans,target , "" , 0, 0,0);
        return ans;
    }
};