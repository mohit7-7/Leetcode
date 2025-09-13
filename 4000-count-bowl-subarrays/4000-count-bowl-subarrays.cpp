class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {

        int ans = 0, maxi = nums[0], n = nums.size();
        for( int i = 1 ; i < n ; i++ ){
            if( nums[i] > nums[i-1] && maxi > nums[i] )
                ans++;
            maxi = max( nums[i], maxi );
        }
        maxi = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i-- ){
            if( nums[i] > nums[i+1] && maxi > nums[i] )
                ans++;
            maxi = max( nums[i], maxi );
        }
        return ans;
    }
}; 