class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n= nums.size()/3;
        int total= 3*n;

        priority_queue<int> maxheap;
        vector<long long>leftmin(total,0);
        long long sum=0;
        for(int i=0;i<2*n;i++){
            maxheap.push(nums[i]);
            sum+= nums[i];
            while(maxheap.size()>n){
                sum -= maxheap.top();
                maxheap.pop();
            }
            leftmin[i]= sum;
        }

        priority_queue<int,vector<int>, greater<int>>minheap;
        vector<long long>rightmax(total,0);
        sum=0;
        for(int i=total-1;i>n-1;i--){
            minheap.push(nums[i]);
            sum+= nums[i];
            while(minheap.size()>n){
                sum-= minheap.top();
                minheap.pop();
            }
            rightmax[i]= sum;
        }

        long long ans= LLONG_MAX;
        for(int i=n-1;i<2*n;i++){
            ans= min(ans, leftmin[i]-rightmax[i+1]);
        }
        return ans;
    }
};