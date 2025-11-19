class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool flag = true;
        while(flag){
            if(find(nums.begin(), nums.end(), original)!= nums.end()){
                original= 2*original;
            }
            else{
                flag = false;
            }
        }
        return original;
    }
};