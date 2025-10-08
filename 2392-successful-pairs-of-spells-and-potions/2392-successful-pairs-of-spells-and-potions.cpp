class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int>pairs(n);
        sort(potions.begin(), potions.end());
        for(int i=0;i<n;i++){
            int spell = spells[i];
            long long target = ceil(success/(double)(1LL*spell));
            int indx=  lower_bound(potions.begin(), potions.end(),target)-potions.begin();
            if(indx==m) pairs[i]= 0;
            else{
                pairs[i]=m-indx;
            }
        }
        return pairs;
    }
};