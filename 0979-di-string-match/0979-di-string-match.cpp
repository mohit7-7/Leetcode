class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n= s.size();
        vector<int>ans(n,0);
        int l=0, r=n;
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                ans[i]= r--;
            }
            else{
                ans[i]= l++;
            }
        }
        ans.push_back(l);
        return ans;
    }
};