/*
Optimal Algorithm
1. Initialize left = 0, right = n - 1, and store the first element as the current answer.
2. While left <= right:
- If the current window is already sorted, update the answer with nums[left] and stop.
- Compute mid.
- Update the answer with nums[mid].
- If the left half is sorted:
- Move search to the right half.
- Otherwise:
- Search in the left half.
3. Return the smallest value found.
*/

class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }
            int m = l + (r - l) / 2;
            res = min(res, nums[m]);

            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
