/*
Recursive Algorithm
1. Define a recursive function that takes counts and characters for all three options.
2. Reorder parameters so the first character has the highest count.
3. Base case: If the second count is zero, return up to two of the first character.
4. Use up to two of the first character. If the remaining count still exceeds the second, use one of the second character.
5. Recurse with updated counts and concatenate the results.
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<char> res = rec(a, b, c, 'a', 'b', 'c');
        return string(res.begin(), res.end());
    }
    private:
    vector<char> rec(int max1, int max2, int max3, char char1, char char2, char char3) {
        if (max1 < max2) {
            return rec(max2, max1, max3, char2, char1, char3);
        }
        if (max2 < max3) {
            return rec(max1, max3, max2, char1, char3, char2);
        }
        if (max2 == 0) {
            vector<char> result(min(2, max1), char1);
            return result;
        }

        int use1 = min(2, max1);
        int use2 = (max1 - use1 >= max2) ? 1 : 0;

        vector<char> res(use1, char1);
        res.insert(res.end(), use2, char2);

        vector<char> rest = rec(max1 - use1, max2 - use2, max3, char1, char2, char3);
        res.insert(res.end(), rest.begin(), rest.end());

        return res;
    }
};