/*
Optimal Algorithm
1. Initialize an empty stack and a result variable set to 0.
2. For each operation:
- If it's +, calculate the sum of the top two elements, push it, and add to result.
- If it's D, calculate double the top element, push it, and add to result.
- If it's C, pop the top element and subtract it from result.
- Otherwise, parse the number, push it, and add to result.
3. Return the result.
*/

class Solution {
public:
    int calPoints(vector<string>& operations){
        stack<int> stack;
        int result{0};
        for (const string& op : operations) {
            if (op == "+") {
                int top = stack.top();
                stack.pop();
                int newTop = top + stack.top();
                stack.push(top);
                stack.push(newTop);
                result += newTop;
            } else if (op == "D") {
                stack.push(2 * stack.top());
                result += stack.top();
            } else if (op == "C") {
                result -= stack.top();
                stack.pop();
            } else {
                stack.push(stoi(op));
                result += stack.top();
            }
        }
        return result;
    }
};