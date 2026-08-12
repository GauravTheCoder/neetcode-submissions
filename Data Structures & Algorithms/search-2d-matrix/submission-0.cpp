/*
Optimal Algorithm
1. Treat the matrix as a single sorted array of size ROWS * COLS.
2. Set l = 0 and r = ROWS * COLS - 1.
3. While l <= r:
- Compute the middle index m = (l + r) // 2.
- Convert m back to matrix coordinates:
- row = m // COLS
- col = m % COLS
- Compare matrix[row][col] with the target:
- If equal → return true.
- If the value is smaller → search the right half (l = m + 1).
- If larger → search the left half (r = m - 1).
4. If the loop ends with no match, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(), COLS = matrix[0].size();

        int l = 0, r = ROWS * COLS - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int row = m / COLS, col = m % COLS;
            if (target > matrix[row][col]) {
                l = m + 1;
            } else if (target < matrix[row][col]) {
                r = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};