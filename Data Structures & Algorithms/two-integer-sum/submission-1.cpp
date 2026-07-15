class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());
        for(int i{0};i<nums.size();++i) {
            int partner = target - nums[i];
            if(seen.count(partner)) {
                return{seen[partner], i};
            }
        seen[nums[i]] = i;
        }
        return{};
    }
};
