/*
Optimal Algorithm
Initialization
1. Insert all initial numbers into a min-heap.
2. If the heap size becomes greater than k, repeatedly remove the smallest element.
- After this, the heap contains exactly k elements.
add(value)
1. Insert the new value into the min-heap.
2. If heap size > k:
- Remove the smallest element (the heap root).
3. Return the heap's smallest element (the root), which is now the k-th largest.
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
