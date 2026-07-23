/*
Optimal Solution
1. Use a sliding window technique with a left and right pointer tracking the current window boundaries.
2. Maintain a frequency array of size 26 for the characters inside the current window and track the maximum frequency of any single character seen so far (max_freq).
3. Expand the window by moving the right pointer and updating the frequency of the new character and the max_freq.
4. Shrink the window from the left by moving the left pointer forward if the current window size minus max_freq exceeds k.
5. Update the frequency array when shrinking the window, though max_freq does not need to be decreased because only a higher max_freq can produce a longer valid window.
6. Calculate the maximum window size achieved during the iteration.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> count(26, 0);
        int max_freq{0};
        int left{0};
        int max_len{0};
        for (int right{0}; right < s.length(); ++right) {
            count[s[right] - 'A']++;
            max_freq = std::max(max_freq, count[s[right] - 'A']);
            if ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};
