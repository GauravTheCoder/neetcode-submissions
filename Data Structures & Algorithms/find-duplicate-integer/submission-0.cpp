/*
Optimal Algorithm
1. Initialize two pointers slow = 0 and fast = 0.
2. Move:
- slow = nums[slow]
- fast = nums[nums[fast]]
until slow == fast.
3. Start a new pointer slow2 = 0.
4. Move both:
- slow = nums[slow]
- slow2 = nums[slow2]
until they meet.
5. The meeting point is the duplicate number.
6. Return that number.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }
};
