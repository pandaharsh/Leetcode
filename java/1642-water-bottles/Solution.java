class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        
        int total = numBottles, new_full, remain;
        while(numBottles >= numExchange){
            new_full = numBottles / numExchange;
            remain = numBottles % numExchange;
            
            total += new_full;
            numBottles = new_full + remain;
        }
        return total;
    }
}