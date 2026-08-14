/*
Optimal Algorithm
1. Set the binary search range: left = max(weights), right = sum(weights).
2. While left <= right:
- Calculate mid = (left + right) / 2.
- Simulate shipping with capacity mid by greedily filling each day's ship.
- If we can ship within the allowed days, update the result and search the left half (r = mid - 1).
- Otherwise, search the right half (l = mid + 1).
3. Return the minimum valid capacity found.
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int res = r;

        while (l <= r) {
            int cap = (l + r) / 2;
            if (canShip(weights, days, cap)) {
                res = min(res, cap);
                r = cap - 1;
            } else {
                l = cap + 1;
            }
        }
        return res;
    }
    private:
    bool canShip(const vector<int>& weights, int days, int cap) {
        int ships = 1, currCap = cap;
        for (int w : weights) {
            if (currCap - w < 0) {
                ships++;
                if (ships > days) {
                    return false;
                }
                currCap = cap;
            }
            currCap -= w;
        }
        return true;
    }
};