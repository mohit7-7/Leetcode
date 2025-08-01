class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n =nums.size();
        vector<int>great(n);
        great[n-1]= nums[n-1];
        for(int i=n-2;i>=0;i--){
            great[i]= max(great[i+1], nums[i]);
        }
        
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++){
            if(great[j]>=nums[i]){
                ans= max(ans,j-i);
            }
            else{
                i++;
                j--;
            }
        }
        return ans;
    }
};