#define ll long long 
class Solution {
public:
    ll findcost(int val, vector<int>&nums, vector<int>&cost){
        ll tcost=0;
        for(int i=0;i<nums.size();i++){
            int steps=abs(nums[i]-val);
            tcost += 1LL*cost[i]*steps;
        }
        return tcost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low= *min_element(nums.begin(), nums.end());
        int high= *max_element(nums.begin(), nums.end());
        ll ans= LLONG_MAX;
        while(low<=high){
            int mid= (low+high)/2;
            ll cost1= findcost(mid, nums, cost);
            ll cost2= findcost(mid+1, nums, cost);
            if(cost1<cost2){
                ans = min(ans,cost1);
                high = mid-1;
            }
            else{
                ans= min(ans, cost2);
                low = mid+2; 
            }
        }
        return ans==LLONG_MAX? 0 : ans;
    }
};