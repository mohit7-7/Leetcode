class Solution {
public:

    void rotate(vector<int>&temp){
        int val= temp[0];
        for(int i=0;i<temp.size()-1;i++){
            temp[i]= temp[i+1];
        }
        temp[temp.size()-1]= val;
    }

    bool check(vector<int>& nums) {
        vector<int> temp= nums;
        sort(temp.begin(), temp.end());
        for(int i=0;i<nums.size();i++){
            if(temp==nums) return true;
            rotate(temp);
        }
        return false;
    }
};