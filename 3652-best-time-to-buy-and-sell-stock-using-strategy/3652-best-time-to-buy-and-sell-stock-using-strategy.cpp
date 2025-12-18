#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& price, vector<int>& strategy, int k) {
        ll ans;
        int n= price.size();
        ll base=0;
        for(int i=0;i<n;i++){
            base += price[i]*strategy[i];
        }
        ans=base;
        for(int i=0;i<k;i++) base -= price[i]*strategy[i];
        ll slide=0;
        for(int i=k/2;i<k;i++) slide += price[i];
        for(int i=k;i<n;i++){
            ans= max(ans, (base+slide));
            int newintoslide = price[i]*strategy[i];
            base -= newintoslide;
            base += price[i-k]*strategy[i-k];
            slide -= price[i-(k/2)];
            slide += price[i];
        }
        ans= max(ans, base+slide);
        return ans;
    }

};