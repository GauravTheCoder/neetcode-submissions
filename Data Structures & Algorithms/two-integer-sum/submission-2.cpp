class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. Overrides standard I/O synchronization to eliminate LeetCode judge lag
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());
        
        for (int i{0}; i < nums.size(); ++i) {
            int partner = target - nums[i];
            
            // 2. Optimization: Use .find() instead of calling .count() then operator[]
            auto it = seen.find(partner);
            if (it != seen.end()) {
                return {it->second, i};
            }
            
            seen[nums[i]] = i;
        }
        return {};
    }
};
