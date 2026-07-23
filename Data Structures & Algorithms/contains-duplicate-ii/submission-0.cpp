/*
Optimal Solution
1. Use a sliding window approach combined with a hash set to maintain elements within a valid index range.
2. Create an empty hash set to store the elements currently inside the sliding window of size k.
3. Iterate through the array from left to right using a pointer i.
4. Before adding the current element nums[i] to the set, check if it already exists in the set.
5. If nums[i] is already in the set, it means a duplicate exists within a distance of at most k, so return true.
6. If it does not exist, insert nums[i] into the hash set.
7. Check if the size of the set or the current index window exceeds k by checking if i >= k.
8. If i >= k, remove the oldest element of the window, which is nums[i - k], from the hash set to keep the window size valid.
9. If the loop completes without triggering a duplicate match, return false.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (window.count(nums[i])) {
                return true;
            }
            
            window.insert(nums[i]);
            
            if (i >= k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};