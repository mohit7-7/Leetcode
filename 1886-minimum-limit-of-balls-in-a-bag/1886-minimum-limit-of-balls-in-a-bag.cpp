class Solution {
public:
    bool steps(int mid, vector<int>&nums, int maxop){
        long long op=0;
        for(int num: nums){
            if(num>mid){
                op += (num-1)/mid;
                if(op>maxop) return false;
            }
        }
        return op<=maxop;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1 , high= *max_element(nums.begin(), nums.end());
        int ans= high;
        while(low<=high){
            int mid= (low+high)/2;
            if(steps(mid, nums, maxOperations)){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            } 
        }
        return ans;  
    }
};