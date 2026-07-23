/*
Optimal Solution
1. Use a sliding window approach with two pointers, left and right, both starting at index 0.
2. Maintain a running sum variable of the elements currently inside the window.
3. Iterate through the array by moving the right pointer forward and adding the current element to the running sum.
4. Shrink the window from the left by moving the left pointer forward while the running sum remains greater than or equal to the target.
5. Update the minimal length found so far using the formula right - left + 1 right before subtracting the leftmost element from the running sum.
6. Return the tracked minimal length if a valid window was found, otherwise return 0.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        int left{0};
        int current_sum{0};
        int min_len{n + 1};
        for (int right{0}; right < n; ++right) {
            current_sum += nums[right];
            while (current_sum >= target) {
                min_len = std::min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }
        return (min_len == n + 1) ? 0 : min_len;
    }
};