/*
Optimal Algorithm
1. Initialize:
- maxArea = 0
- An empty stack to store indices of bars (with heights in increasing order).
2. Loop i from 0 to n (inclusive):
- While the stack is not empty and either:
- i == n (we're past the last bar, acting like height 0), or
- heights[i] is less than or equal to the height at the top index of the stack:
- Pop the top index; let its height be h.
- Compute the width:
- If the stack is empty, width = i (it extends from 0 to i - 1).
- Otherwise, width = i - stack.top() - 1.
- Update maxArea with h * width.
- Push the current index i onto the stack.
3. After the loop, maxArea holds the largest rectangle area. Return it.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> stack;

        for (int i = 0; i <= n; i++) {
            while (!stack.empty() &&
                 (i == n || heights[stack.top()] >= heights[i])) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
};
