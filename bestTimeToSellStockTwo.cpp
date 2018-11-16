class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int maxProfit = 0; // Will return this
        int peak; // Will store peak at ith position
        int valley; // Will store valley at ith position
        int i = 0; // Iterator
        int size = prices.size(); // Size variable so that you don't have to do prices.size() again and again
        
        //Setting inital
        peak = prices[0];
        valley = prices[0];
        while(i < size - 1) {
            //finding valley at which you will buy
            while(i < size-1 && prices[i] >= prices[i+1]) {
                i++;  
            }
            valley = prices[i];
            while(i < size-1 && prices[i] <= prices[i+1]) {
                i++;    
            }
            peak = prices[i];
            maxProfit += (peak - valley);
        }
        return maxProfit;
    }
};
