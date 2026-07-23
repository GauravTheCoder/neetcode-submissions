/*
Optimal Solution
1. Initialize a variable to store the maximum profit and set it to 0.
2. Initialize another variable to track the minimum buying price seen so far, setting it to the price of the first day.
3. Iterate through the prices array starting from the first day to the end using a single loop.
4. For each day, check if the current price is less than the minimum buying price tracked so far. If it is, update the minimum buying price with the current price.
5. If the current price is not smaller, calculate the potential profit if you were to sell on the current day by subtracting the minimum buying price from the current price.
6. Compare this potential profit with the maximum profit tracked so far and update the maximum profit if the new value is larger.
7. Return the maximum profit after completing the single pass through the array.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int max_profit{0};
        int min_price{prices[0]};
        
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                max_profit = std::max(max_profit, prices[i] - min_price);
            }
        }
        
        return max_profit;
    }
};
