/*
Optimal Algorithm
1. Make an empty max-heap.
2. For each point:
- Compute its squared distance from origin: d = x^2 + y^2.
- Insert (d, point) into the heap.
- If heap size exceeds k:
- Remove the element with the maximum distance.
3. After processing all points:
- The heap contains exactly the k closest points.
4. Return all points stored in the heap.
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist, {point[0], point[1]}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first,
                           maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
    }
};
