class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_sums;
        // Base case: A prefix sum of 0 has occurred once (handles subarrays starting from index 0)
        prefix_sums[0] = 1;
        
        int current_sum = 0;
        int total_subarrays = 0;
        
        for (int num : nums) {
            current_sum += num;
            
            // Check if there is a prefix subarray we can remove to get sum 'k'
            if (prefix_sums.count(current_sum - k)) {
                total_subarrays += prefix_sums[current_sum - k];
            }
            
            // Record the current prefix sum frequency
            prefix_sums[current_sum]++;
        }
        
        return total_subarrays;
    }
};