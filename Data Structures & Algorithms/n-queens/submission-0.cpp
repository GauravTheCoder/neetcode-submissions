/*
Optimal Algorithm
1. Initialize three integers (bit masks):
- col → tracks used columns
- posDiag → tracks row + col
- negDiag → tracks row - col + n
2. Initialize an empty n x n board filled with ".".
3. Start backtracking from row 0.
4. For each c (column) in the current r (row):
- Check conflicts using bitwise AND:
- col & (1 << c)
- posDiag & (1 << (r + c))
- negDiag & (1 << (r - c + n))
- If any is set → skip
5. If safe:
- Set bits using XOR (^=) to mark column and diagonals
- Place "Q" at (r, c)
- Recurse to row r + 1
6. If r == n:
- Convert the board to string format and save it
7. Backtrack:
- Remove the queen
- Toggle the same bits back using XOR
8. Continue until all valid boards are generated.
*/
class Solution {
public:
    int col = 0, posDiag = 0, negDiag = 0;
    vector<string> board;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));

        backtrack(0, n);
        return res;
    }

    void backtrack(int r, int n) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if ((col & (1 << c)) || (posDiag & (1 << (r + c)))
                 || (negDiag & (1 << (r - c + n)))) {
                continue;
            }
            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));
            board[r][c] = 'Q';

            backtrack(r + 1, n);

            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));
            board[r][c] = '.';
        }
    }
};

