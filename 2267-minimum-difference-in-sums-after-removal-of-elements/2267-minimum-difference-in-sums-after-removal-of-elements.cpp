class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n= nums.size()/3;
        vector<int>isselected(3*n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        for(int i=0;i<2*n;i++){
            minheap.push({nums[i],i});
        }
        long long sumfirst=0;
        for(int i=0;i<n;i++){
            int indx=minheap.top().second;
            int val= minheap.top().first;
            sumfirst+= val;
            isselected[indx]=1;
            minheap.pop();
        }
        priority_queue<int>maxheap;
        for(int i=n;i<3*n;i++){
            if(!isselected[i]){
                maxheap.push(nums[i]);
            }
        }

        long long sumsecond=0;
        for(int i=0;i<n;i++){
            sumsecond+= maxheap.top();
            maxheap.pop();
        }

        return sumfirst-sumsecond;
    }
};