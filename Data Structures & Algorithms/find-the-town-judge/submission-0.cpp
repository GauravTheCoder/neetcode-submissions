/*
Optimal Algorithm
1. Create a single array delta of size n + 1.
2. For each trust pair [a, b]:
- Decrement delta[a] (person a trusts someone, reducing their score).
- Increment delta[b] (person b is trusted, increasing their score).
3. Iterate through persons 1 to n:
- If delta[i] == n - 1, return i.
4. Return -1 if no judge found.
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n + 1, 0);

        for (auto& t : trust) {
            delta[t[0]]--;
            delta[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (delta[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};