class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n= fruits.size();
        int m= baskets.size();
        int count=0;
        int i=0,j=0;

        while(i<n && j<m){
            if(fruits[i]<= baskets[j]){
                baskets[j]=-1;
                j=0;
                i++;
                continue;
            }
            if(j==m-1){
                count++;
                j=0;
                i++;
            }
            else
                j++; 
        }
        return count;
    }
};