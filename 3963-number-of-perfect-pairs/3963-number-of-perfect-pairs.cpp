#define ll long long 
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        ll count=0;
        vector<int> absvalue;
        int n= nums.size();
        for(int num: nums){ absvalue.push_back(abs(num));  }
        sort(absvalue.begin(), absvalue.end());
        int i=0,j=0;
        while(j<n){
            while(absvalue[j]> 2*absvalue[i]){
                i++;
            }
            if(i>j)j=i;
            count+= (j-i);
            j++;
        }
        return count;
    }
};