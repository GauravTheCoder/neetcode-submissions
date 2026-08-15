/*
Optimal Algorithm
1. Let the two sorted arrays be A and B. Ensure A is the smaller array (swap if needed).
2. Let:
- total = len(A) + len(B)
- half = total // 2
3. Use binary search on A:
- l = 0, r = len(A) - 1
- While searching:
- Let i be the cut index in A (midpoint of l and r).
- Let j = half - i - 2 be the cut index in B
(so that total elements on the left of both arrays equals half).
4. Define border values around the cut:
- Aleft = A[i] if i >= 0 else -∞
- Aright = A[i + 1] if i + 1 < len(A) else +∞
- Bleft = B[j] if j >= 0 else -∞
- Bright = B[j + 1] if j + 1 < len(B) else +∞
5. Check if the partition is valid:
- If Aleft <= Bright and Bleft <= Aright:
- We found the correct partition.
- If total is odd:
- Median = min(Aright, Bright)
- Else (even total):
- Median = (max(Aleft, Bleft) + min(Aright, Bright)) / 2
- Else if Aleft > Bright:
- Move the cut in A left → set r = i - 1.
- Else (Bleft > Aright):
- Move the cut in A right → set l = i + 1.
6. Return the median computed from the valid partition.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};
