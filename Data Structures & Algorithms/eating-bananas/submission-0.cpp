/*
Optimal Algorithm
1. Set the search range:
- left = 1 (minimum possible speed)
- right = max(piles) (maximum needed speed)
2. While left <= right:
- Let mid be the current speed to test.
- Compute the total hours needed using this speed.
3. If the total hours is within the allowed time h:
- This speed works, so record it.
- Try to find a smaller working speed by searching the left half.
4. Otherwise:
- Speed is too slow, so search in the right half.
5. After the search ends, return the smallest valid speed found.
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = (l + r) / 2;

            long long totalTime = 0;
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k);
            }
            if (totalTime <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
