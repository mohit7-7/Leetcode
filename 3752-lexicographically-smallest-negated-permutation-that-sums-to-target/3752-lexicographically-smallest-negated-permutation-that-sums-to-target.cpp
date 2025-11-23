#define ll long long
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        ll sum =0;
        for(int i=1;i<=n;i++){
            sum += i;
        }
        if(sum < target) return {};
        ll diff = sum - target;
        if(diff % 2 !=0) return {};
        diff /=2;
        vector<int>ans(n);
        for(int i=1;i<=n;++i)ans[i-1]=i;
        for(int i=n-1;i>=0;i--){
            if(ans[i]> diff) continue;
            diff -= ans[i];
            ans[i]= -ans[i];
        }
        if(diff !=0) return {};
        sort(ans.begin(), ans.end());
        return ans;
    }
};