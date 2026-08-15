/*
Optimal Algorithm
1. Set l = max(nums) and r = sum(nums).
2. Binary search while l <= r:
- For mid, check if we can split into at most k subarrays with max sum <= mid.
- The check greedily adds elements until the sum exceeds mid, then starts a new subarray.
- If feasible, record mid as a candidate and search for smaller values.
- Otherwise, search for larger values.
3. Return the smallest feasible value.
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canSplit(nums, k, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    private:
    bool canSplit(vector<int>& nums, int k, int largest) {
        int subarray = 1, curSum = 0;
        for (int num : nums) {
            curSum += num;
            if (curSum > largest) {
                subarray++;
                if (subarray > k) return 0;
                curSum = num;
            }
        }
        return true;
    }
};