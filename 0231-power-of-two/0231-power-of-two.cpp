class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        int low=0, high= log2(n);
        while(low<=high){
            int mid = (low+high)/2;
            long long val= 1LL*1<<mid;
            if(n==val){
                return true;
            }
            else if(val<n){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};