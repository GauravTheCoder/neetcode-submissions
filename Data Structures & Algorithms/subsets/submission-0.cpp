/*
Backtracking Algorithm
1. Maintain:
- res → final list of all subsets
- subset → current subset being built
2. Define a recursive function dfs(i):
- If i equals the length of the input:
- Add a copy of subset to res
- Return
- Choice 1: include nums[i]
- Append number to subset
- Recurse to next index
- Remove the number (backtrack)
- Choice 2: skip nums[i]
- Recurse to next index
3. Start recursion with dfs(0)
4. Return res
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }
    private:
    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res);
        subset.pop_back();
        dfs(nums, i + 1, subset, res);
    }
};
