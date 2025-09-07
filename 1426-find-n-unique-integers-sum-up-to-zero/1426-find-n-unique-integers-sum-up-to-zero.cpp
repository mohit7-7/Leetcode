class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        vector<int>ans(n);
        int val=1;
        for(int i=0;i<n;i++){
            if(i%2==0) ans[i]= val++;
            else ans[i]= -ans[i-1];
        }
        if(n%2!=0){
            ans[n-3]=val;
            ans[n-2]=val+1;
            ans[n-1]= -(ans[n-3]+ans[n-2]);
        }
        return ans;
    }
};