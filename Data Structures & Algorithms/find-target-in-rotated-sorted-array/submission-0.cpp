/*
Optimal Algorithm
1. Use binary search to find the pivot:
- Compare middle element with the rightmost element.
- If nums[mid] > nums[right], the pivot is in the right half.
- Otherwise, it's in the left half.
2. Once the pivot is identified:
- The subarray before the pivot is one sorted half.
- The subarray starting at the pivot is the other sorted half.
3. Perform a standard binary search on:
- The left half; if found, return the index.
- Otherwise, search the right half.
4. If the target is not in either half, return -1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;

        int result = binarySearch(nums, target, 0, pivot - 1);
        if (result != -1) {
            return result;
        }
        return binarySearch(nums, target, pivot, nums.size() - 1);
    }
        int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
