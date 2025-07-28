class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int n= nums.length();
        int i=0,j=0; 
        int countT=0, flips=0;

        while(j<n){
            if(nums[j]=='F') flips++;
            while(flips>k){
                if(nums[i]=='F')flips--;
                i++;
            }
            countT= max(countT, j-i+1);
            j++;
        }
        i=0,j=0,flips=0;
        int countF=0;
        while(j<n){
            if(nums[j]=='T')flips++;
            while(flips>k){
                if(nums[i]=='T')flips--;
                i++;
            }
            countF= max(countF,j-i+1);
            j++;
        }

        return max(countT, countF);
    }
};