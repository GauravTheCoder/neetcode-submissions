class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;       // Pointer for valid elements in nums1
        int p2 = n - 1;       // Pointer for elements in nums2
        int p = m + n - 1;    // Pointer for the insertion slot at the back of nums1
        
        // Merge from back to front
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
        // If there are remaining elements in nums2, copy them over.
        // Elements remaining in nums1 are already sorted and in place.
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};