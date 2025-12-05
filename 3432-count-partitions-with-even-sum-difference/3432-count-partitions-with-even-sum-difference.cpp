class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n= nums.size();
        vector<int>ps(n+1,0);
        for(int i=1;i<=n;i++){
            ps[i]= ps[i-1]+ nums[i-1];
        }

        int count =0;
        for(int i=1;i<n;i++){
            int right = ps[n]-ps[i];
            if((right-ps[i])%2==0){
                count++;
            }
        }
        return count;
    }
};

