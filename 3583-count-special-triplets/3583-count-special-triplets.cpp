class Solution {
public:
    int m = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        long long count=0;
        int n = nums.size();
        unordered_map<int,int>right;
        unordered_map<int,int>left;
        for(int num: nums){
            right[num]++;
        }

        for(int num : nums){
            right[num]--;
            if(right[num]==0) right.erase(num);
            if(right.count(num*2) && left.count(num*2)) count= (count+1LL*left[num*2]*right[num*2])%m;
            left[num]++;
        }
        
        return count;
    }
};