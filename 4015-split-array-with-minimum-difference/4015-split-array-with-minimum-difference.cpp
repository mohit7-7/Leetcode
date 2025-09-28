#define ll long long
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<ll>ps(n);
        ps[0] =nums[0];
        int count= 0;
        int flagindx= -1;
        for(int i=1;i<n;i++){
            if(!count){if(nums[i]> nums[i-1]) continue;
            else{
                count++;
                flagindx= i-1;
                continue;
            }
            }
            if(count){
                if(nums[i]>=nums[i-1]){
                    count++;
                    break;
                }
            }
        }

        if(count==2) return -1;
        for(int i=1;i<nums.size();i++){
            ps[i]= ps[i-1]+nums[i];
        }
        
        if(flagindx==0){
            return abs(ps[0]-(ps[n-1]-ps[0]));
        }
        if(flagindx==-1){
            return abs(ps[n-2]-(ps[n-1]-ps[n-2]));
        }
        ll sum1= ps[flagindx];
        ll sum2= ps[n-1]-ps[flagindx];
        ll diff1 = labs(sum1-sum2);
        sum1= ps[flagindx-1];
        sum2= ps[n-1]-ps[flagindx-1];
        ll diff2= labs(sum1-sum2);         
        return min(diff1, diff2);
    }
};