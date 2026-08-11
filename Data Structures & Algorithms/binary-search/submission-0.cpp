/*
Recursive Implementation
1. Define a recursive function that takes the current search range [l, r].
2. If l > r, the range is empty, return -1.
3. Compute the middle index m = (l + r) // 2.
4. Compare nums[m] with target:
- If equal, return m.
- If nums[m] < target, recursively search [m + 1, r].
- If nums[m] > target, recursively search [l, m - 1].
5. Start the recursion with the full range [0, n - 1].
6. Return the final result.
*/

class Solution {
public:
    int binary_search(int l, int r, vector<int>& nums, int target){
        if (l > r) return -1;
        int m = l + (r - l) / 2;

        if (nums[m] == target) return m;
        return ((nums[m] < target) ?
                binary_search(m + 1, r, nums, target) :
                binary_search(l, m - 1, nums, target));
    }
    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, nums, target);
    }
};
