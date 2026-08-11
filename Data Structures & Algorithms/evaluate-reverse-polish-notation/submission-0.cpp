/*
Optimal Algorithm
1. Create an empty stack.
2. For each token:
- If it is a number, convert it to an integer and push it onto the stack.
- If it is an operator:
- Pop the top two numbers.
- Apply the operator in the correct order.
- Push the result back onto the stack.
3. After processing all tokens, the stack contains exactly one value — return it.
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& c : tokens) {
            if (c == "+") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b + a);
            } else if (c == "-") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            } else if (c == "*") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b * a);
            } else if (c == "/") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            } else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};
