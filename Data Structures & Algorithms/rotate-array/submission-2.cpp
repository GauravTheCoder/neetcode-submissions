class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;

        int count = 0;
        for (int start = 0; count < n; ++start) {
            int current = start;
            int prev_val = nums[start];
            
            do {
                int next_idx = (current + k) % n;
                int temp = nums[next_idx];
                nums[next_idx] = prev_val;
                prev_val = temp;
                current = next_idx;
                count++;
            } while (start != current);
        }
    }
};