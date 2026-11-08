/*
SweepLine Algorithm
1. Create a map mp to store boundary changes:
- for each interval [start, end]:
- increment mp[start] (interval starts)
- decrement mp[end] (interval ends)
2. Initialize:
- have = 0 to track how many intervals are currently active
- interval = [] to build the current merged interval
- res = [] to store the final merged intervals
3. Iterate through all keys in mp in sorted order:
4. For each position i:
- If interval is empty, this position may mark the start of a new merged interval:
- set interval = [i]
- Update the active count:
- have += mp[i]
- If have == 0:
- all intervals have closed at this point
- append i as the end of the current merged interval
- add interval to res
- reset interval to empty
5. After processing all events, return res
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_val = 0;
        for (const auto& interval : intervals) {
            max_val = max(interval[0], max_val);
        }

        vector<int> mp(max_val + 1, 0);
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(end + 1, mp[start]);
        }

        vector<vector<int>> res;
        int have = -1;
        int intervalStart = -1;
        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] != 0) {
                if (intervalStart == -1) intervalStart = i;
                have = max(mp[i] - 1, have);
            }
            if (have == i) {
                res.push_back({intervalStart, have});
                have = -1;
                intervalStart = -1;
            }
        }

        if (intervalStart != -1) {
            res.push_back({intervalStart, have});
        }

        return res;
    }
};