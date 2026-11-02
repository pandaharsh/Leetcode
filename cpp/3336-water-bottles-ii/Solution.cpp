class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
       
        int total = numBottles; 
        
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            numExchange += 1;

            total += 1;
            numBottles += 1; 
        }
        
        return total;
    }
};