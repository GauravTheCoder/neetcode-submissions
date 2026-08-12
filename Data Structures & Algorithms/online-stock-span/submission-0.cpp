/*
Optimal Algorithm
1. Initialize an empty stack that stores pairs of (price, span).
2. For each next(price) call:
- Start with span = 1 (counting today).
- While the stack is not empty and the top price is less than or equal to the current price:
- Pop the top element and add its span to the current span.
- Push (price, span) onto the stack.
- Return span.
*/

class StockSpanner {
    stack<pair<int, int>> stack; // pair: (price, span)
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!stack.empty() && stack.top().first <= price) {
            span += stack.top().second;
            stack.pop();
        }
        stack.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */