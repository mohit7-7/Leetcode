class Solution {
public:
    bool check(int mid, vector<int> nums){
        nums[0]= nums[0]+mid;
        bool check= true;
        for(int i=1;i<nums.size();i++) {
            nums[i]= nums[i-1]+nums[i];
            if(nums[i]<1) check =false;
        }
        return check;
    }
    int minStartValue(vector<int>& nums) {
        int currsum=nums[0];
        int high=nums[0];
        for(int i=1;i<nums.size();i++){
            currsum += nums[i];
            high= min(high, currsum);
        }
        if(high<0)high = -(high-1);
        int low = (nums[0]<0)?-(nums[0]-1):1;
        int ans=1;
        while(low<=high){
            int mid= (high+low)/2;
            if(check(mid,nums)){
                ans = mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};