class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        for(int num: nums){
            auto gcdd = [&](auto self, int a, int b) -> int {
                return (b == 0) ? a : self(self, b, a % b);
            };

            ans.push_back(num);
            while(ans.size()>1){
                int num1= ans.back();
                int num2= ans[ans.size()-2];
                if(gcdd(gcdd,num1, num2)==1) break;
                ans.pop_back();
                ans.pop_back();
                int lcmm= (1LL*num1*num2)/gcdd(gcdd,num1, num2);
                ans.push_back(lcmm);
            }
        }
        return ans;
    }
};



