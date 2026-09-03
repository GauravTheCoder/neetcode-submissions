/*
Optimal Algorithm
1. Define a recursive function dfs(i, currentList, total) where:
- i is the current index in nums
- currentList is the current combination being built
- total is the sum of numbers in currentList
2. If total == target, add a copy of currentList to the result and return.
3. If i goes out of bounds or total exceeds the target, return (stop exploring).
4. Choose to include nums[i]:
- Add nums[i] to currentList
- Call dfs(i, currentList, total + nums[i]) (stay at same index)
- Remove nums[i] (backtrack)
5. Choose to skip nums[i]:
- Call dfs(i + 1, currentList, total)
6. Start with dfs(0, [], 0) and return the result list.
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target){
        vector<int> cur;
        backtrack(nums, target, cur, 0);
        return res;
    }
        void backtrack(vector<int>& nums, int target, vector<int>& cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }

        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], cur, i);
        cur.pop_back();
        backtrack(nums, target, cur, i + 1);
    }
};
