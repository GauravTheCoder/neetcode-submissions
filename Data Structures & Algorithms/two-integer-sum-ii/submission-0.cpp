class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left{0}, right{static_cast<int>(numbers.size())-1};
        while(left < right) {
            int cur_sum{numbers[left] + numbers[right]};
            if(cur_sum == target) {
                return {left+1, right+1};
            }
            else if(cur_sum < target) {
                left++;
            }
else {
                right--;
            }
        }
        return {};
    }
};