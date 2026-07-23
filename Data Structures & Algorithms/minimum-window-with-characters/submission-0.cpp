/*
Optimal Solution
1. Create a frequency map for all characters in string t and maintain a variable required_count equal to the total number of unique characters in t that need to be matched.
2. Initialize two pointers, left and right, at the beginning of string s to form a sliding window, alongside a tracking map for characters inside the window.
3. Expand the window by moving the right pointer forward and adding characters to the window map.
4. Increment a matching counter if the frequency of the current character matches its required frequency in t.
5. Shrink the window from the left by advancing the left pointer as long as the matching counter equals required_count.
6. Record the minimum window length and its starting index every time a valid window is shrunk.
7. Decrement the matching counter if shrinking the window causes a required character's frequency to fall below its needed count in t.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";
        std::vector<int> mapT(128, 0);
        for (char c : t) mapT[c]++;
        std::vector<int> mapS(128, 0);
        int required{ 0};
        for (int i{0}; i < 128; ++i) {
            if (mapT[i] > 0) required++;
        }
        int left{0}, right{0};
        int formed{0};
        int minLen{INT_MAX};
        int startIdx{0};
        while (right < s.length()) {
            char c = s[right];
            mapS[c]++;
            if (mapT[c] > 0 && mapS[c] == mapT[c]) {
                formed++;
            }
            while (left <= right && formed == required) {
                c = s[left];
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }
                mapS[c]--;
                if (mapT[c] > 0 && mapS[c] < mapT[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};