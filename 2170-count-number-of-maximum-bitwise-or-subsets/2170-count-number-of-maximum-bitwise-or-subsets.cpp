class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> subsetsor={0};
        for (int num : nums) {
            int size = subsetsor.size();
            for (int i = 0; i < size; ++i) {
                int newSubsetor = subsetsor[i];
                newSubsetor |= num;
                subsetsor.push_back(newSubsetor);
            }
        }
        int maximum= *max_element(subsetsor.begin(), subsetsor.end());
        return count(subsetsor.begin(), subsetsor.end(), maximum);
    }
};