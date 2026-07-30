/*
Optimal Algorithm
1. Create a stack to store opening brackets.
2. For each character c in the string:
- If it is an opening bracket, push it onto the stack.
- If it is a closing bracket:
- Check if the stack is not empty and its top matches the corresponding opening bracket.
- If yes, pop the stack.
- Otherwise, return false.
3. After processing all characters:
- If the stack is empty, return true.
- Otherwise, return false.
*/

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
