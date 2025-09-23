class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if(nums1==nums2)return 0;
        int n=nums1.size();

        queue<pair<vector<int>,int>>q;
        set<vector<int>>vis;
        q.push({nums1,0});
        while(!q.empty()){
            auto [curr,steps]=q.front();
            q.pop();
            if(curr==nums2)return steps;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    vector<int>currSub(curr.begin()+i,curr.begin()+j+1);
                    vector<int>restArray;
                    for(int k=0;k<n;k++){
                        if(k<i || k>j)restArray.push_back(curr[k]);
                    }

                    for(int k=0;k<=restArray.size();k++){
                        vector<int>temp;
                        temp.insert(temp.end(),restArray.begin(),restArray.begin()+k);
                        temp.insert(temp.end(),currSub.begin(),currSub.end());
                        temp.insert(temp.end(),restArray.begin()+k,restArray.end());

                        if(vis.find(temp)==vis.end()){
                            vis.insert(temp);
                            q.push({temp,steps+1});
                        }
                    }
                    
                }
            }
        }
        return n-1;
        
        
    }
};