class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> subsetsor={0};
        int max= 0, count=0;
        for (int num : nums) {
            int size = subsetsor.size();
            for (int i = 0; i < size; ++i) {
                int newSubsetor = subsetsor[i]| num;
                if(newSubsetor> max){
                    max= newSubsetor;
                    count=1;
                }
                else if(max==newSubsetor ) count++;
                subsetsor.push_back(newSubsetor);
            }
        }
        // int maximum= *max_element(subsetsor.begin(), subsetsor.end());
        // return count(subsetsor.begin(), subsetsor.end(), maximum);
        return count;
    }
};