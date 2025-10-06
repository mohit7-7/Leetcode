class Solution {
public:
    void solve(set<vector<int>>&ans, vector<int>&nums,vector<int>&temp, int indx){
        if(indx== nums.size()){
            ans.insert(temp);
        }

        for(int i=indx ;i<nums.size();i++){
            solve(ans, nums, temp,i+1);
            temp.push_back(nums[i]);
            solve(ans, nums, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        solve(ans, nums,temp, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};