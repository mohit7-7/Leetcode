class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips=0;
        int flipcount=0;
        vector<int>isflipped(n,0);
        for(int i=0;i<n;i++){
            if(i>=k && isflipped[i-k]==true){
                flipcount--;
            }
            if(nums[i]== flipcount%2){
                if(i+k >n ) return -1;
                flipcount++;
                flips++;
                isflipped[i]= true;
            }
        }
        return flips;
    }
};