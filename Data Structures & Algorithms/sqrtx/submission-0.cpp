/*
Optimal Algorithm
1. Initialize l = 0, r = x, and res = 0 to store the answer.
2. While l <= r:
- Compute middle m = l + (r - l) / 2.
- If m * m > x, the answer must be smaller, so set r = m - 1.
- If m * m < x, m is a valid candidate. Store it in res and search for a larger value by setting l = m + 1.
- If m * m == x, we found the exact square root, so return m.
3. Return res after the loop.
*/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int res = 0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((long long) m * m > x) {
                r = m - 1;
            } else if ((long long) m * m < x) {
                l = m + 1;
                res = m;
            } else {
                return m;
            }
        }

        return res;
    }
};