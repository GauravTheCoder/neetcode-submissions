/*
Optimal Algorithm
1. Put all treasure cells (grid[r][c] == 0) into a queue.
2. Mark them visited. Walls (-1) are never added.
3. Set dist = 0.
4. While the queue is not empty:
- Process all nodes currently in the queue (this is one BFS level = distance dist).
- For each cell popped:
- Set grid[r][c] = dist (distance to nearest treasure).
- Try its 4 neighbors:
- If in bounds, not a wall, and not visited -> mark visited and push to queue.
- After finishing the level, do dist += 1.
5. After BFS ends, every reachable empty room has been updated with its shortest distance; unreachable rooms remain INF.
*/

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if (r < 0 || r >= m || c < 0 ||
                    c >= n || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};