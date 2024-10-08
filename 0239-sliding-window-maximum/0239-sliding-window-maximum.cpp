class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        int n= nums.size()-1;
        ans.push_back(pq.top().first);
        for(int i=k;i<=n;i++){ 
            while(!pq.empty()&& pq.top().second <=(i-k)){
                pq.pop();
            }
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};