#define ll long long 
class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high= x;
        int ans=0;
        while(low<=high){
            int mid= (low+high)/2;
            if(((ll)mid*(ll)mid)==x) return mid;
            if((mid * mid)<x){
                ans= mid;
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return ans;
    }
};