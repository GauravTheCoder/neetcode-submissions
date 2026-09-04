/*
Optimal Algorithm
1. Let ROWS, COLS be grid size.
2. Define dfs(r, c, i) meaning: "Can we match word[i...] starting from cell (r, c)?"
3. Base case: if i == len(word), we matched all characters → return true.
4. Fail cases: if out of bounds, current cell doesn't match word[i], or cell is already used ('#') → return false.
5. Mark the cell as used (set it to '#').
6. Try DFS in 4 directions with i + 1.
7. Restore the cell back to its original character (backtrack).
8. Run dfs(r, c, 0) from every cell (r, c). If any returns true, answer is true; otherwise false.
*/

class Solution {
public:
    int ROWS, COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }

        board[r][c] = '#';
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);
        board[r][c] = word[i];
        return res;
    }
};
