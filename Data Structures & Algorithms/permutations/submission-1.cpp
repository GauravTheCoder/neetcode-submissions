/*
Backtracking Algorithm
1. Start backtracking from idx = 0.
2. If idx == len(nums), we have a full permutation → append a copy to result.
3. For each index i from idx to end:
- Swap nums[idx] and nums[i]
(placing nums[i] in the current position)
- Recurse with idx + 1
- Swap back to restore original order (backtracking)
4. Continue until all permutations are generated.
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

        void backtrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            backtrack(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};
