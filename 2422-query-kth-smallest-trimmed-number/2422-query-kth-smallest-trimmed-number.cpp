class Solution {
public:
    int findksmallest(vector<int>&nums, int k){
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int i=0;
        for(int num : nums){
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
            vector<int> newnums;
            
            for(string num : nums){
                newnums.push_back(stoi(num.substr(trimindx)));
            }
            
            int val= findksmallest(newnums,k);
            ans.push_back(val);

        }
        return ans;
    }
};