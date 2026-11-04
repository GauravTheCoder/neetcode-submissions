/*
BFS Algorithm
1. Iterate through every cell in the grid.
2. When a land cell (1) is found:
- Start bfs from that cell.
- Mark it as visited by setting it to 0.
- Initialize area count to 1.
3. During bfs:
- Pop a cell from the queue.
- Check its 4 neighbors (up, down, left, right).
- If a neighbor is valid land (1), add it to the queue, mark it 0, and increase area.
4. After bfs completes, update the maximum area.
5. Continue scanning the grid.
6. Return the maximum area found.
*/

class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0},
                            {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int area = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    area = max(area, bfs(grid, r, c));
                }
            }
        }

        return area;
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});
        int res = 1;

        while (!q.empty()) {
            auto node = q.front();q.pop();
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                    res++;
                }
            }
        }
        return res;
    }
};