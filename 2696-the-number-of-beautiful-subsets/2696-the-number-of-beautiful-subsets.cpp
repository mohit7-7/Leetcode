class Solution {
public:
    unordered_map<int, int>mp;
    void solve(vector<int>&nums, int k , int &count, int indx){
        if(indx== nums.size()){
            count++;
            return;
        }

        int num = nums[indx];
        if(!mp.count(num-k) && !mp.count(num+k)){
            mp[num]++;
            solve(nums, k, count, indx+1);
            mp[num]--;
            if(mp[num]==0) {
                mp.erase(num);
            }
        }
        solve(nums, k , count , indx+1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int count=0;
        solve(nums, k, count, 0);
        return count-1;
    }
};