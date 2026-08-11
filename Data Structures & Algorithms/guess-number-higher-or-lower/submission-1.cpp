
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 Optimal Algorithm
 1. Initialize two pointers: l = 1 and r = n.
2. Calculate the middle value m = (l + r) / 2.
3. Call guess(m):
- If it returns 0, we found the number; return m.
- If it returns 1 (number is higher), set l = m + 1.
- If it returns -1 (number is lower), set r = m - 1.
4. Repeat until the number is found.
 */



class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (true) {
            int m = l + (r - l) / 2;
            int res = guess(m);
            if (res > 0) {
                l = m + 1;
            } else if (res < 0) {
                r = m - 1;
            } else {
                return m;
            }
        }
    }
};