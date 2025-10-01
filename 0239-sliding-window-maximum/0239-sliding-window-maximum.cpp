class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        multiset<int, greater<int>>pq;
        int j=0,i=0;
        vector<int>ans;
        while(j<n){
            pq.insert(nums[j]);
            while(j-i>=k){
                pq.erase(pq.find(nums[i]));
                i++;
            }
            if(j-i+1==k){
                ans.push_back(*pq.begin());
            }
            j++;
        }
        return ans;
    }
};