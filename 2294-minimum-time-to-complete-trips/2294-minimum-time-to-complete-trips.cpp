#define ll long long
class Solution {
public:
    bool possible(ll mid,int totalTrips, vector<int>&time){
        ll trips=0;
        for(int t: time){
            trips += mid/t;
        }
        return trips>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low = *min_element(time.begin(), time.end());
        ll maxelement = *max_element(time.begin(), time.end());
        ll high = maxelement*1LL*totalTrips;
        ll ans= 0;
        while(low<= high){
            ll mid= low+(high-low)/2;
            if(possible(mid,totalTrips,time)){
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