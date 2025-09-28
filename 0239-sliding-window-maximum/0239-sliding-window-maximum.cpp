class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>ans;
        int i=0, j=0;
        multiset<int, greater<int>> pq; 
        while(j<n){
            pq.insert(nums[j]);
            if(j-i+1==k){
                ans.push_back(*pq.begin());
                pq.erase(pq.find(nums[i]));
                i++;
            }
            j++;
        }
        return ans;
    }
};