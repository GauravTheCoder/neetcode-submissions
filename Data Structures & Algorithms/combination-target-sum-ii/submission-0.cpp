/*
Backtracking Algorithm
1. Sort the candidates.
2. Define a DFS function dfs(idx, path, curSum):
- If curSum == target, add a copy of path to the result.
- Loop i from idx to end:
- If i > idx and the current number equals the previous → skip (duplicate control).
- If adding this number exceeds target → break (pruning).
- Include the number and recurse with i + 1 (cannot reuse same element).
- Backtrack by removing the last number.
3. Call dfs(0, [], 0) and return the result.
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return res;
    }
    private:
    void dfs(int idx, vector<int> path, int cur, vector<int>& candidates, int target) {
        if (cur == target) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (cur + candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);
            dfs(i + 1, path, cur + candidates[i], candidates, target);
            path.pop_back();
        }
    }
};
