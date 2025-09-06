class Solution {
public:
    bool ispossible(int mid, vector<int>&piles, int h){
        long long time=0;
        for(int num: piles){
            time += ceil((double)num/(double)mid);
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1, high= *max_element(piles.begin(), piles.end());
        int ans=-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(ispossible(mid,piles,h)){
                ans= mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};