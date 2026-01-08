class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
        int startindx=0;
        int currgas =0;
        for(int i=0;i<gas.size();i++){
            currgas += gas[i]- cost[i];
            totalgas += gas[i] - cost[i];
            if(currgas<0){
                currgas=0;
                startindx = i+1;
            }
        }
        if(totalgas< 0) return -1;
        return startindx;
    }
};