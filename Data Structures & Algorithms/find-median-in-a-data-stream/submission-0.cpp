/*
Optimal Algorithm
1. Initialize
- Create two heaps:
- small -> max-heap for lower half
- large -> min-heap for upper half
2. addNum(x)
- If large is not empty and x is greater than the smallest element in large,
insert into large.
- Otherwise insert into small.
- Rebalance:
- If one heap becomes larger than the other by more than 1,
move the top element to the other heap.
3. findMedian()
- If one heap has more elements:
- Median = top of that heap.
- If both heaps have equal elements:
- Median = average of both heap tops.
*/

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        smallHeap.push(num);
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } else if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};
