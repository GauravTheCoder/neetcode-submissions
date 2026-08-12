/*
Optimal Algorithm
1. Initialize two stacks: one for strings (stringStack) and one for counts (countStack).
2. Maintain a current string cur and a current multiplier k.
3. Iterate through each character:
- If it's a digit, update k = k * 10 + digit.
- If it's [, push cur and k onto their respective stacks, then reset cur to empty and k to 0.
- If it's ], pop the previous string and count. Set cur to the popped string plus the current string repeated by the popped count.
- Otherwise, append the character to cur.
4. Return cur as the final decoded string.
*/

class Solution {
public:
    string decodeString(string s) {
        vector<string> stringStack;
        vector<int> countStack;
        string cur = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                stringStack.push_back(cur);
                countStack.push_back(k);
                cur = "";
                k = 0;
            } else if (c == ']') {
                string temp = cur;
                cur = stringStack.back();
                stringStack.pop_back();
                int count = countStack.back();
                countStack.pop_back();
                for (int i = 0; i < count; i++) {
                    cur += temp;
                }
            } else {
                cur += c;
            }
        }

        return cur;
    }
};