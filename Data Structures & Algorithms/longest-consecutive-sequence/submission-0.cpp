class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Insert all numbers into a hash set for O(1) lookup
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int max_streak = 0;
        
        for (int num : num_set) {
            // Check if 'num' is the start of a sequence
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int current_streak = 1;
                
                // Incrementally look for the next elements of the sequence
                while (num_set.count(current_num + 1)) {
                    current_num += 1;
                    current_streak += 1;
                }
                
                // Track the longest sequence found
                max_streak = std::max(max_streak, current_streak);
            }
        }
        
        return max_streak;
    }
};
