class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n= nums.size();
        deque<int>flipq;
        int flipcount=0;
        int totalflips=0;
        for(int i=0;i<n;i++){
            if(i>=k){
                flipcount -= flipq.front();
                flipq.pop_front();
            }
            if(nums[i] == flipcount%2){
                if(i+k>n) return -1;
                flipq.push_back(1);
                flipcount++;
                totalflips++;
            }
            else{
                flipq.push_back(0);
            }
        }
        return totalflips;
    }
};