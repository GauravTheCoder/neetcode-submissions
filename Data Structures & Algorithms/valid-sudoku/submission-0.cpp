class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Bitmasks to track seen numbers (1-9) for rows, columns, and 3x3 boxes
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                
                // Convert char digit to a 0-indexed integer bit position (0 to 8)
                int val = board[r][c] - '1';
                int mask = 1 << val;
                
                // Determine the 3x3 box index
                int box_idx = (r / 3) * 3 + (c / 3);
                
                // Check if the bit is already set in the row, column, or box
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[box_idx] & mask)) {
                    return false;
                }
                
                // Set the bit to record that we've seen this number
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[box_idx] |= mask;
            }
        }
        
        return true;
    }
};
