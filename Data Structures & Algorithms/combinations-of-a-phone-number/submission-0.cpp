/*
Backtracking Algorithm
1. If the input string is empty, return an empty list.
2. Create a mapping from digits (2-9) to their corresponding letters.
3. Use a recursive function backtrack(index, currentString):
- If currentString length equals the number of digits:
- Add it to the result.
- Return.
- Otherwise:
- For each character mapped from digits[index]:
- Append the character to currentString
- Recurse to the next index.
4. Start backtracking from index 0 with an empty string.
5. Return all collected combinations.
*/

class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(0, "", digits);
        return res;
    }
        void backtrack(int i, string curStr, string &digits) {
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            backtrack(i + 1, curStr + c, digits);
        }
    }
};
