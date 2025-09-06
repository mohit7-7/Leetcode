class Solution {
public:
    bool ispossible(int wperday, vector<int>&weights, int days){
        long long time=1;
        long long temp= wperday;
        for(int i=0;i<weights.size();i++){
            temp -= weights[i];
            if(temp<0){
                temp= wperday;
                time++;
                i--;
            }
        }
        return (time<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(), weights.end());
        int high= accumulate(weights.begin(), weights.end(),0);
        int ans=0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(ispossible(mid, weights, days)){
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