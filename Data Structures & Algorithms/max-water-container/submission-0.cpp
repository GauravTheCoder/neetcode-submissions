/*
Optimal Solution
1. Use a two-pointer approach to find the maximum water container efficiently.
2. Place a left pointer at the beginning of the array (index 0) and a right pointer at the end of the array (index length - 1).
3. Calculate the distance between the two pointers as the width of the container.
4. Determine the usable height of the container by taking the minimum value between the heights at the left and right pointers.
5. Multiply the width by this height to get the current water area, and update the maximum area if this value is larger than the previous maximum.
6. To maximize the area, move the pointer that points to the shorter line inward by one position. This is because keeping the shorter line can never produce a larger area with a smaller width.
7. Repeat the process of calculating area and moving the pointer with the shorter line until the left and right pointers meet.
*/

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water {0};
        int left{0};
        int right {static_cast<int>(heights.size())-1};
        
        while (left < right) {
            int width = right - left;
            int current_height = std::min(heights[left], heights[right]);
            int current_water = width * current_height;
            
            max_water = std::max(max_water, current_water);
            
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};