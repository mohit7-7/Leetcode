class Solution {
public:
    
    int custombs(vector<vector<int>>&items, int querysize){
        int l=0,r=items.size()-1,mid;
        int maxi= 0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(items[mid][0]>querysize){
                r=mid-1;
            }
            else{
                maxi = max(items[mid][1],maxi);
                l=mid+1;
            }
        }
        return maxi;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        int m= queries.size();
        vector<int>ans(m);
        sort(items.begin(), items.end());
        int maxeleseen=items[0][1];
        for(int i=1;i<n;i++){
            maxeleseen = max(maxeleseen,items[i][1]);
            items[i][1]= maxeleseen;
        }
        
        for(int i=0;i<m;i++){
            int querysize= queries[i];
            ans[i]=custombs(items,querysize);
        }
        return ans;
    }
};