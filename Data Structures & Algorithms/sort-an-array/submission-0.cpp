class Solution {
private:
    // Helper function to maintain the max-heap property
    void heapify(std::vector<int>& nums, int n, int i) {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index

        // If left child is larger than root
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            std::swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build max heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Step 2: Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            std::swap(nums[0], nums[i]);

            // Call max heapify on the reduced heap
            heapify(nums, i, 0);
        }

        return nums;
    }
};