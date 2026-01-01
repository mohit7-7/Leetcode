class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end() , greater<int>());
        int n = happiness.size()-1;
        long long maxans= 0;
        int i = 0;
        while(k--){
                happiness[i] =max(happiness[i] - i , 0);
                maxans += happiness[i];
                i++;
        }
        return maxans;
    }
};