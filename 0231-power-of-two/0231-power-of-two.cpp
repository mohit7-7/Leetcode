class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        int low=0, high = log2(n);
        while(low<=high){
            int mid= (low+high)/2;
            int val= (1<<mid);
            if(val==n) return true;
            if(val < n) low= mid+1;
            else high= mid-1;
        }
        return false;
    }
};