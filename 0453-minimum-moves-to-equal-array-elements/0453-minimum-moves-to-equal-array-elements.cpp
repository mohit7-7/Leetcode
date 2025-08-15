class Solution {
public:
    int minMoves(vector<int>& nums) {
    int mini = *min_element(nums.begin(), nums.end());
    int sum= accumulate(nums.begin(), nums.end(),0);
    int ans = sum- (mini*nums.size());
    return ans;
}

};