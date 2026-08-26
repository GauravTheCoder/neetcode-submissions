/*
Optimal Algorithm
1. Create an array of indices [0, 1, 2, ..., n-1] and sort it based on the tasks' enqueue times.
2. Initialize time to 0, and create a min-heap that compares indices by their task's processing time (then by index for ties).
3. Iterate through sorted indices:
- Push indices of tasks that have become available onto the heap.
- If the heap is empty and tasks remain, jump time forward.
- Otherwise, pop the best task, update time, and record the result.
4. Return the execution order.
*/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0] ||
                   (tasks[a][0] == tasks[b][0] && a < b);
        });

        auto comp = [&](int a, int b) {
            return tasks[a][1] > tasks[b][1] ||
                   (tasks[a][1] == tasks[b][1] && a > b);
        };
        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);

        vector<int> result;
        long long time = 0;
        int i = 0;

        while (!minHeap.empty() || i < n) {
            while (i < n && tasks[indices[i]][0] <= time) {
                minHeap.push(indices[i]);
                i++;
            }

            if (minHeap.empty()) {
                time = tasks[indices[i]][0];
            } else {
                int nextIndex = minHeap.top();
                minHeap.pop();
                time += tasks[nextIndex][1];
                result.push_back(nextIndex);
            }
        }
        return result;
    }
};