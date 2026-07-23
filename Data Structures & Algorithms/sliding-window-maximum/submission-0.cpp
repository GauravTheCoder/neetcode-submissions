/*
Optimal Solution
1. Use a doubly-ended queue (deque) to store the indices of the array elements.
2. Maintain the deque in a monotonically decreasing order of element values, meaning the index of the largest element in the current window is always at the front.
3. Iterate through the array from the beginning to the end using a loop index i.
4. Remove indices from the front of the deque if they fall outside the boundary of the current sliding window, which happens when deque.front() <= i - k.
5. Remove indices from the back of the deque as long as the elements they point to are smaller than or equal to the current element nums[i], since they can no longer be the maximum.
6. Push the current index i onto the back of the deque.
7. Append the element at the front index of the deque to the results array for every position where the window has reached at least size k, which is when i >= k - 1.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq;
        for (int i{0}; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};