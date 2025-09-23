class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if(nums1 == nums2) return 0;
        int n = nums1.size();
        queue<vector<int>> q;
        q.push(nums1);
        map<vector<int>, int> dist;
        dist[nums1] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int d = dist[it];
            
            for(int l = 0; l < n; l++){
                
                for(int r = l; r < n; r++){
                    vector<int> v;
            vector<int> temp;
                    for(int k = l; k <= r;k++)v.push_back(it[k]);
                    for(int i = 0; i < l; i++) temp.push_back(it[i]);
                    for(int i = r + 1; i < n; i++) temp.push_back(it[i]);

                    for(int i = 0; i < (int)temp.size(); i++){
                        vector<int> temp2 = temp;
                        temp2.insert(temp2.begin() + i, v.begin(), v.end());
                        if(dist.find(temp2) == dist.end()){
                        dist[temp2] = 1 + d;
                        if(temp2 == nums2) return dist[temp2];
                        q.push(temp2);
                        
                    }
                    }

                    
                }
            }
        }
        return -1;
        
    }
};