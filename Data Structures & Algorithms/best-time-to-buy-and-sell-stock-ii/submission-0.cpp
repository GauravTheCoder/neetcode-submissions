class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        // Loop through the array starting from the second day
        for (size_t i = 1; i < prices.size(); ++i) {
            // If the price increased compared to the previous day, take the profit
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        
        return max_profit;
    }
};