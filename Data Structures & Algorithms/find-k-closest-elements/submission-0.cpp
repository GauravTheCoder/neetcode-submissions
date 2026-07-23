/*
Optimal Solution
1. Use binary search to locate the optimal starting index of the contiguous subarray of size k.
2. Set the binary search range for the left index low from 0 to N - k.
3. Evaluate the middle index mid during each binary search step by checking the boundaries of the window of size k starting at mid.
4. Compare the distance of the element just outside the window on the left x - arr[mid] against the distance of the element just outside the window on the right arr[mid + k] - x.
5. Shift the binary search window to the right by setting low = mid + 1 if the element at mid + k is closer to x than the element at mid.
6. Shift the window to the left by setting high = mid if the element at mid is closer or equally close to x.
7. Extract the subarray of length k starting from the final calculated low index.
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low{ 0};
        int high{static_cast<int>(arr.size() )- k};
        while (low < high) {
            int mid{low + (high - low) / 2};
            if (x - arr[mid] > arr[mid + k] - x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return std::vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};