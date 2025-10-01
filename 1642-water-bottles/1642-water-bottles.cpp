class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans= numBottles;
        int newbottles= (numBottles/numExchange);
        int remaining = numBottles%numExchange;
        while(newbottles >= 1){
            ans+= newbottles;
            int temp= newbottles;
            newbottles = (newbottles+remaining)/numExchange;
            remaining = (temp+remaining)%numExchange;
        }
        return ans;
    }
};