class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int num : nums){
            if(st1.find(num)!= st1.end()){
                st2.insert(num);
            }
            else{
                st1.insert(num);
            }
        }
        return vector<int>(st2.begin(), st2.end());
    }
};