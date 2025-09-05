class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(), nums.end());
        int n= nums.size();
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
