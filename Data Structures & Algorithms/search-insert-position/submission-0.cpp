/*
Optimal Algorithm
1. Initialize pointers l = 0 and r = n - 1.
2. While l <= r:
- Compute mid = (l + r) / 2.
- If nums[mid] == target, return mid.
- If nums[mid] > target, search left with r = mid - 1.
- Otherwise, search right with l = mid + 1.
3. Return l as the insertion index (where l naturally lands on the correct position).
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};