/*
Backtracking Algorithm
1. Initialize res = 0 to accumulate the sum of XOR totals.
2. Define a backtracking function that takes the current index and the current subset:
- Compute the XOR of all elements in the subset and add it to res.
- For each remaining element starting from the current index:
- Add the element to the subset.
- Recursively call backtrack with the next index.
- Remove the element from the subset.
3. Call the backtracking function starting at index 0 with an empty subset.
4. Return res.
*/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        vector<int> subset;

        function<void(int)> backtrack = [&](int i) {
            int xorr = 0;
            for (int num : subset) xorr ^= num;
            res += xorr;

            for (int j = i; j < nums.size(); ++j) {
                subset.push_back(nums[j]);
                backtrack(j + 1);
                subset.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};