/*
Optimal Solution
1. Use a sliding window approach with two pointers, left and right, both starting at the beginning of the string.
2. Maintain a hash map or integer array to store the last seen index of each character.
3. Iterate through the string with the right pointer.
4. Update the left pointer to max(left, last_seen_index + 1) if the current character was already seen inside the current window.
5. Calculate the current window length as right - left + 1 and update the maximum length found so far.
6. Store the current index of the character in the map and move the right pointer forward.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> mpp(256, -1);
        int left{0}, right{0};
        int n{static_cast<int>(s.size())};
        int len{0};
        while (right < n) {
            if (mpp[s[right]] != -1) {
                left = std::max(mpp[s[right]] + 1, left);
            }
            mpp[s[right]] = right;
            len = std::max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
