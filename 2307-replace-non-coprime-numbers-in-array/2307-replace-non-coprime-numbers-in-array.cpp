class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        for(int num: nums){
            ans.push_back(num);
            auto gcdd=  [](int num1,int num2){
                return (num2==0)? num1: gcd(num2, num1%num2);
            };
            while(ans.size()>1){
                int num1= ans.back();
                int num2= ans[ans.size()-2];
                if(gcdd(num1, num2)==1) break;
                ans.pop_back();
                ans.pop_back();
                int lcmm= (1LL*num1*num2)/gcd(num1, num2);
                ans.push_back(lcmm);
            }
        }
        return ans;
    }
};



