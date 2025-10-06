class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&nums,vector<int>&temp, int indx){
        if(indx== nums.size()){
            ans.push_back(temp);
            return ;
        }

        solve(ans, nums, temp, indx+1);
        temp.push_back(nums[indx]);
        solve(ans, nums, temp, indx+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans, nums,temp, 0);
        return ans;
    }
};