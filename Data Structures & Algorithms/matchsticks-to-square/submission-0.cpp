/*
Optimal Algorithm
1. Calculate the total length and target side length. Return false if total is not divisible by 4.
2. Sort matchsticks in descending order for early pruning.
3. In the recursive function, try placing the current matchstick on each side:
- Skip if adding the matchstick would exceed the target length.
- If placement succeeds recursively, return true.
- Backtrack by removing the matchstick.
- If the current side is empty after backtracking, stop trying other sides (they are equivalent).
4. Return true if all matchsticks are placed successfully.
*/

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLength % 4 != 0) return false;

        int length = totalLength / 4;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, sides, 0, length);
    }
    private:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int length) {
        if (index == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= length) {
                sides[i] += matchsticks[index];
                if (dfs(matchsticks, sides, index + 1, length)) return true;
                sides[i] -= matchsticks[index];
            }

            if (sides[i] == 0) break;
        }

        return false;
    }
};