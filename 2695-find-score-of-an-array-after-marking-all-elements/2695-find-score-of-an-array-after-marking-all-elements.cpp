class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n= nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool>ismarked(n,false);
        int i=0;
        for(int num: nums){
            pq.push({num,i});
            i++;
        }

        long long ans=0;
        while(!pq.empty()){
            int val= pq.top().first;
            int indx= pq.top().second;
            if(!ismarked[indx]){
                ismarked[indx]= true;
                if(indx>0)ismarked[indx-1]=true;
                if(indx<n-1)ismarked[indx+1]= true;
                ans+= val;
            }
            pq.pop();
            while(!pq.empty() && ismarked[pq.top().second]){
                pq.pop();
            }
        }
        return ans;
    }
};

