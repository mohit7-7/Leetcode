class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> isbasketused(baskets.size(),0);
        int count=0;
        for(int fruit:fruits){
            bool placed= false;
            for(int i=0;i<baskets.size();i++){
                if(baskets[i]>=fruit && !isbasketused[i]){
                    placed=true;
                    isbasketused[i]=1;
                    break;
                }
            }
            if(!placed) count++;
        }
        return count;
    }
};