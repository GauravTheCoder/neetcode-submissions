class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for(int num:nums) {
            counts[num]++;
        }
        std::vector<std::vector<int>> buckets(nums.size()+1);
        for(auto&p:counts) {
            buckets[p.second].push_back(p.first);
        }
        std::vector<int> result;
                for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }
        
        return result;
    }
};
