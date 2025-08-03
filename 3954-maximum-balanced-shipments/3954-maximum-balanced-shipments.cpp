class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();;
        if(n==0 || n==1) return 0;
        int i=0;
        int j=1;
        int maxelement= weight[0];
        int ans=0;
        while(j<n){
            if(weight[j]< maxelement){
                i= j+1;
                ans++;
                if(i<n) maxelement= weight[i];
                j++;
            }else{
                maxelement= max(weight[j], maxelement);
            }
            j++;
        }
        return ans;
    }
};