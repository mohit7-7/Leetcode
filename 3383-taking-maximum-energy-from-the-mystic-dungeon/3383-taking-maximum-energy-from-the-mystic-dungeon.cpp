class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n= energy.size();
        vector<int>temp(n);

        for(int i=0;i<n;i++){
            int maxp = energy[i];
            if(i-k>=0){
                maxp = max(maxp, energy[i]+ temp[i-k]);
            }
            temp[i]= maxp;
        }

        int ans = INT_MIN;
        for(int i=n-k; i<n;i++){
            ans= max(ans, temp[i]);
        }

        return ans;
    }
};