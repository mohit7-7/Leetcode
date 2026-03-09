class Solution {
public:
    int mod = 1e9+7;
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return -1;
        // if(n==2) return 
        vector<long long>leftsum(n,0);
        vector<long long>rightpro(n, 1);
        for(int i=1;i<n;i++){
            leftsum[i]= (leftsum[i-1]+ nums[i-1]);
        }

        long long limit = leftsum[n-1];
        for(int i=n-2;i>=0;i--){
             if(rightpro[i+1] > limit / max(1, nums[i+1]))
                rightpro[i] = limit + 1;
            else
                rightpro[i] = rightpro[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++){
            if(leftsum[i]== rightpro[i]) return i;
        }
        return -1;
    }
};

