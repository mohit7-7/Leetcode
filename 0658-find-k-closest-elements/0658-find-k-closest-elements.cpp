class Solution {
public:
    int diff(int x, int y){
        return abs(x-y);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({diff(arr[i],x),i});
        }
        vector<int>ans;
        while(k--){
            int indx= pq.top().second;
            ans.push_back(arr[indx]);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};