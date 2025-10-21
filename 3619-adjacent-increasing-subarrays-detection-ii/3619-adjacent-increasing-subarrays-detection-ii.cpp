class Solution {
public:
    bool check(int k, vector<int>inc){
        int n= inc.size();
        for(int i=k;i<n;i++){
            if(inc[i]>=k && inc[i-k]>=k) return true;
        }
        return false;
    }
    
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n= nums.size();
        vector<int>inc(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]> nums[i-1]) inc[i]= inc[i-1]+1;
        }

        int ans=1;
        int low =1, high= n/2;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid,inc)){
                ans = mid;
                low = mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return ans;
    }
};

// 1 2 3 4 5 6 n = 6 so max k =3