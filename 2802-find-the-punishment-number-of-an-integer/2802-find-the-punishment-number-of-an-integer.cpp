class Solution {
public:
    bool ispossible(int target , string&num, int indx){
        if(indx==num.size() && target==0){
            return true;
        }

        if(indx==num.size()) return false;

        for(int i= indx;i<num.size();i++){
            // if(i!=indx && num[indx]=='0') break;
            string part= num.substr(indx, i-indx+1);
            int val = stoi(part);
            if(ispossible(target-val, num, i+1)){
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            long sq= i*i;
            string sqq= to_string(sq);
            if(ispossible(i,sqq,0)){
                ans+=sq;
            }
        }
        return ans;
    }
};