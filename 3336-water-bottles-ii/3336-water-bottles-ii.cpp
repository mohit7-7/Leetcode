class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total=0;
        while(numBottles){
            if(numExchange > numBottles){
                return total+numBottles;
            }
            total += numExchange;
            numBottles = (numBottles-numExchange) + 1; 
            numExchange++;
        }
        return total;
    }
};

