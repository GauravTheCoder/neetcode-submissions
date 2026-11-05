/*
Optimal BFS Algorithm
1. Count fresh oranges (value 1).
2. Repeat while fresh > 0:
- Set flag = false (did we rot anything this minute?).
- Scan every cell:
- If cell is 2, check 4 neighbors.
- For each neighbor that is 1, mark it 3, decrement fresh, set flag = true.
- If flag is false → no progress → return -1.
- Scan again and convert all 3 to 2 (commit the next BFS layer).
- Increment time.
3. When fresh == 0, return time.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int fresh = 0, time = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) fresh++;
            }
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1},
                                          {1, 0}, {-1, 0}};

        while (fresh > 0) {
            bool flag = false;
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (grid[r][c] == 2) {
                        for (auto& d : directions) {
                            int row = r + d[0], col = c + d[1];
                            if (row >= 0 && col >= 0 &&
                                row < ROWS && col < COLS &&
                                grid[row][col] == 1) {
                                grid[row][col] = 3;
                                fresh--;
                                flag = true;
                            }
                        }
                    }
                }
            }

            if (!flag) return -1;

            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (grid[r][c] == 3) grid[r][c] = 2;
                }
            }

            time++;
        }

        return time;
    }
};