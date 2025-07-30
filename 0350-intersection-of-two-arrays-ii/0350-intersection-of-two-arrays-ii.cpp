class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>ans1;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans1[nums1[i]]++;
        }
        for(int j=0;j<nums2.size();j++){
            if(ans1[nums2[j]]>0){
                ans1[nums2[j]]--;
                ans.push_back(nums2[j]);
            }
        }

        return ans ;
    }
};