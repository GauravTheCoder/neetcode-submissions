/*
Backtracking Algorithm
1. Sort the input list to group duplicates.
2. Use a recursive function backtrack(i, subset):
- Add the current subset to the result.
- For each index j from i to the end:
- If j > i and nums[j] == nums[j-1]: skip duplicate choices.
- Include nums[j] into the subset.
- Recursively call backtrack(j + 1, subset).
- Remove the element to backtrack.
3. Start with backtrack(0, []).
4. Return the result.
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, {}, nums);
        return res;
    }
    void backtrack(int i, vector<int> subset, vector<int>& nums) {
        res.push_back(subset);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }
            subset.push_back(nums[j]);
            backtrack(j + 1, subset, nums);
            subset.pop_back();
        }
    }
};
