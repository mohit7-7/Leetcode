class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>ans1;
        int i=0,j=0;
        for(int i=0;i<nums1.size();i++){
            ans1.insert(nums1[i]);
        }
        vector<int>ans;
        for(int j=0;j<nums2.size();j++){
            if(ans1.count(nums2[j])){
                ans1.erase(nums2[j]);
                ans.push_back(nums2[j]);
            }
        }

        return ans ;
    }
};