/*
Backtracking Algorithm
1. Start with an empty combination and a starting index of 1.
2. If the combination size equals k, save a copy to the result and return.
3. Iterate from the start index to n. For each number, add it to the combination.
4. Recursively call with start = i + 1 to only consider larger numbers.
5. Remove the last element (backtrack) before trying the next number.
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        vector<int> comb;
        backtrack(1, n, k, comb);
        return res;
    }
        void backtrack(int start, int n, int k, vector<int>& comb) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i <= n; i++) {
            comb.push_back(i);
            backtrack(i + 1, n, k, comb);
            comb.pop_back();
        }
    }
};