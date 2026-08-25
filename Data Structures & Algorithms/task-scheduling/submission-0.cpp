/*
Heap Algorithm
1. Count how many times each task appears.
2. Build a max-heap where each entry is "remaining count" of a task (the higher the count, the higher its priority).
3. Create an empty queue (FIFO) to store pairs: (remaining_count_after_running, next_available_time).
4. Set time = 0.
5. While the heap is not empty or the cooldown queue is not empty:
1. Increment time by 1.
2. If the heap is not empty:
- Pop the task with the largest remaining count.
- "Run" it once: remaining_count -= 1.
- If remaining_count > 0, push (remaining_count, time + n) into the cooldown queue (it can be used again after n units).
3. Check the front of the cooldown queue:
- While the task at the front has next_available_time == time,
remove it from the queue and push its remaining_count back into the max-heap.
4. (Optional optimization)
- If the heap is empty and the cooldown queue is not empty:
- Let next_time be the next_available_time of the front element in the cooldown queue.
- Set time = next_time (fast-forward), then process step 3 again for that time.
6. When both the heap and cooldown queue are empty, return time as the minimum time required to finish all tasks.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
