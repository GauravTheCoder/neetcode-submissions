/*
BSearch  Algorithm
1. If the list is empty, return [newInterval].
2. Use binary search to find the first index left where:
- intervals[left].start >= newInterval.start
- this is the position where newInterval should be inserted
3. Insert newInterval into intervals at index left.
4. Initialize an empty list res.
5. Iterate through the (now sorted) intervals:
- If res is empty or the current interval starts after the last interval in res ends:
- append the current interval to res
- Otherwise (overlap exists):
- merge by updating the last interval’s end:
- res[-1].end = max(res[-1].end, current.end)
6. Return res.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int target = newInterval[0];
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        intervals.insert(intervals.begin() + left, newInterval);

        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
