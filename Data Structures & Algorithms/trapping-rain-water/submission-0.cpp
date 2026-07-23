/*
Optimal Solution
1. Use a two-pointer approach with two markers: left at the beginning (index 0) and right at the end (index length - 1) of the array.
2. Maintain two variables, left_max and right_max, both initialized to 0, to track the highest bars seen from each direction.
3. Loop while the left pointer is less than or equal to the right pointer.
4. Compare the heights at the left and right positions.
5. If the height at left is less than or equal to the height at right, check if height[left] is greater than or equal to left_max.
6. If it is, update left_max with height[left]. If not, add left_max - height[left] to the total water count, then move the left pointer one step to the right.
7. If the height at right is smaller than the height at left, check if height[right] is greater than or equal to right_max.
8. If it is, update right_max with height[right]. If not, add right_max - height[right] to the total water count, then move the right pointer one step to the left.
9. Return the accumulated water sum once the pointers meet.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n{static_cast<int>(height.size())};
        if (n == 0) return 0;

        int left{0};
        int right{n-1};
        int left_max{0};
        int right_max{0};
        int total_water ={0};

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    total_water += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    total_water += right_max - height[right];
                }
                right--;
            }
        }

        return total_water;
    }
};
