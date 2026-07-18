class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {        int n = nums.size();
        
        // Step 1: Cyclic Sort to place numbers in their respective slots
        for (int i = 0; i < n; ++i) {
            // Keep swapping until the element is in its correct place
            // nums[i] should be stored at index nums[i] - 1
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first index where the correct number is missing
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If 1 to n are all present, the missing number is n + 1
        return n + 1;

    }
};