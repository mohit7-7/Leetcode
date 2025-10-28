class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int  n = nums.size();
        vector<int>ps(n);
        ps[0]= nums[0];
        for(int i=1;i<n;i++){
            ps[i]= ps[i-1]+nums[i];
        }

        int count=0;
        int i=0;
        for(int num : nums){
            if(num==0){
                int diff = (ps[n-1]-ps[i]);
                if(ps[i] == diff) count+=2;
                else if(abs(ps[i]-diff)==1) count+=1;
            }
            i++;
        }
        return count;
    }
};

