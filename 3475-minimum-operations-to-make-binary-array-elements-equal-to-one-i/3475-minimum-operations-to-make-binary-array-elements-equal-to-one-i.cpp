class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips=0;
        int n= nums.size();
        int flipscount=0;
        for(int i=0;i<n;i++){
            if(i>=3 && nums[i-3]==2){
                flipscount--;
            }
            if(nums[i]== flipscount%2){
                if(i+3>n) return -1;
                flipscount++;
                flips++;
                nums[i]= 2; //matlab yha pe flip marra hu mai
            }
        }
        return flips;
    }
};