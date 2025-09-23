class Solution {
public:
    int findksmallest(vector<string>& nums, int k){
    vector<pair<string,int>> arr;
    for(int i=0;i<nums.size();i++){
        arr.push_back({nums[i],i});
    }
    nth_element(arr.begin(), arr.begin()+k-1, arr.end());
    // kth smallest will be at arr[k-1] but need full ordering for tie-breaking
    sort(arr.begin(), arr.begin()+k);
    return arr[k-1].second;
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