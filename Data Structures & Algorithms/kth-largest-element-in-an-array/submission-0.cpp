/*
Heap Algorithm
1. Create an empty min-heap.
2. Iterate through each number:
- Push the number into the min-heap.
- If the heap size exceeds k, pop the smallest element.
3. After processing all numbers, the top of the heap is the k-th largest element.
4. Return that value.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
