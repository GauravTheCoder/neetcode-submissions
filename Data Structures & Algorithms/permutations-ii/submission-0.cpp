/*
Optimal Algorithm
1. Sort nums so duplicates are adjacent.
2. Use backtracking starting at index 0:
- If index i equals the length of nums, add a copy of nums to the result.
- Otherwise, for each index j from i to the end:
- Skip if j > i and nums[j] equals nums[i] (duplicate at this position).
- Swap nums[i] and nums[j], then recurse with i + 1.
- After the loop, restore the array by reverse-swapping elements back from the end to i + 1.
3. Return all permutations.
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }
        void dfs(int i, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[i]) continue;
            swap(nums[i], nums[j]);
            dfs(i + 1, nums);
        }

        for (int j = nums.size() - 1; j > i; --j) {
            swap(nums[i], nums[j]);
        }
    }
};