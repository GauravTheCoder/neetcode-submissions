/*
Optimal Algorithm
1. Initialize three integers col, posDiag, and negDiag to 0.
2. Define a backtracking function that takes the current r (row):
- If r equals n, increment the solution count and return.
- For each c (column) in the row:
- Check if the bit at position c in col, position r + c in posDiag, or position r - c + n in negDiag is set. If any is set, skip this column.
- Toggle the corresponding bits using XOR.
- Recursively call backtrack for the next row.
- Toggle the bits again to restore the previous state (backtrack).
3. Start backtracking from row 0 and return the final count.
*/
class Solution {
public:
    int col = 0, posDiag = 0, negDiag = 0;
    vector<string> board;

    int totalNQueens(int n) {
        int res = 0;
        backtrack(0, n, res);
        return res;
    }

    void backtrack(int r, int n, int& res) {
        if (r == n) {
            res++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if ((col & (1 << c)) || (posDiag & (1 << (r + c))) ||
                (negDiag & (1 << (r - c + n)))) {
                continue;
            }
            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));

            backtrack(r + 1, n, res);

            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));
        }
    }
};
