/*
Optimal Algorithm
1. Initialize two pointers l = 0 and r = n - 1.
2. While l <= r:
- Compute m = l + (r - l) / 2.
- If nums[m] equals the target, return true.
- If nums[l] < nums[m], the left half is sorted:
- If the target lies in [nums[l], nums[m]), search left by setting r = m - 1.
- Otherwise, search right by setting l = m + 1.
- Else if nums[l] > nums[m], the right half is sorted:
- If the target lies in (nums[m], nums[r]], search right by setting l = m + 1.
- Otherwise, search left by setting r = m - 1.
- Else (nums[l] == nums[m]), increment l to skip the duplicate.
3. Return false if the loop ends without finding the target.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) {
                return true;
            }

            if (nums[l] < nums[m]) { // Left portion
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (nums[l] > nums[m]) { // Right portion
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                l++;
            }
        }

        return false;
    }
};