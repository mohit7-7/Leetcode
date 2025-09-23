class Solution {
public:
    int findksmallest(vector<string>&nums, int k){
        priority_queue<pair<string,int>, vector<pair<string,int>> , greater<pair<string,int>>> pq;
        int i=0;
        for(string num : nums){
            pq.push({num , i++});
        }

        int indx =-1;
        while(k--){
            indx = pq.top().second;
            pq.pop();
        }
        return indx;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int numsize= nums[0].length();
        for(auto& query: queries){
            int k= query[0];
            int trim= query[1];
            int trimindx = numsize-trim;
            vector<string> newnums;
            
            for(string num : nums){
                newnums.push_back((num.substr(trimindx)));
            }
            
            int val= findksmallest(newnums,k);
            ans.push_back(val);

        }
        return ans;
    }
};