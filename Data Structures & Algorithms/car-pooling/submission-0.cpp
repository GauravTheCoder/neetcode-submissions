/*
Optimal Algorithm
1. Sort trips by their pickup location.
2. Use a min-heap to track active trips, ordered by their drop-off location.
3. For each trip:
- Pop all trips from the heap whose drop-off location is at or before the current pickup, subtracting their passengers from the count.
- Add the current trip's passengers to the count.
- If the count exceeds capacity, return false.
- Push the current trip (drop-off time, passenger count) onto the heap.
4. Return true if all trips are processed without exceeding capacity.
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // [end, numPassengers]
        int curPass = 0;

        for (const auto& trip : trips) {
            int numPass = trip[0], start = trip[1], end = trip[2];

            while (!minHeap.empty() && minHeap.top().first <= start) {
                curPass -= minHeap.top().second;
                minHeap.pop();
            }

            curPass += numPass;
            if (curPass > capacity) {
                return false;
            }

            minHeap.emplace(end, numPass);
        }
        return true;
    }
};