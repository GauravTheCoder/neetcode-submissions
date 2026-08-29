/*
Optimal Algorithm
1. Create an array of indices [0, 1, ..., n-1] and sort it by capital[index].
2. Initialize a max-heap for profits and a pointer idx = 0.
3. Repeat up to k times:
- While idx < n and capital[indices[idx]] <= w, push profits[indices[idx]] onto the max-heap and increment idx.
- If the max-heap is empty, break.
- Pop the maximum profit and add it to w.
4. Return w.
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return capital[a] < capital[b];
        });

        priority_queue<int> maxProfit;
        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < n && capital[indices[idx]] <= w) {
                maxProfit.push(profits[indices[idx]]);
                idx++;
            }
            if (maxProfit.empty()) {
                break;
            }
            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};