/*
Optimal Algorithm
1. Convert every stone weight x into -x and build a min-heap.
2. While the heap contains more than one stone:
- Pop two values a and b (these represent the two heaviest stones).
- If a != b, compute the remaining stone weight:
- diff = a - b (still negative)
- Push diff back into the heap.
3. After the loop:
- If the heap is empty, return 0.
- Otherwise return the absolute value of the remaining stone.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int s : stones) {
            maxHeap.push(s);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if (second < first) {
                maxHeap.push(first - second);
            }
        }

        maxHeap.push(0);
        return maxHeap.top();
    }
};
