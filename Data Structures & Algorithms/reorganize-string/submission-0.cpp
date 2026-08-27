/*
Heap Algorithm
1. Count frequencies and build a maxHeap of (count, character) pairs.
2. Track a prev element that was just used and cannot be immediately reused.
3. While the maxHeap is not empty or prev exists:
- If prev exists but the maxHeap is empty, return an empty string.
- Pop the top element cnt, append its character, and decrement cnt.
- Push prev back to the maxHeap if it exists.
- Set prev to the current element if its count is still positive.
4. Return the res string.
*/

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char& c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], 'a' + i});
            }
        }

        string res = "";
        pair<int, char> prev = {0, ' '};
        while (!maxHeap.empty() || prev.first > 0) {
            if (prev.first > 0 && maxHeap.empty()) {
                return "";
            }

            auto [count, char_] = maxHeap.top();
            maxHeap.pop();
            res += char_;
            count--;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = {count, char_};
        }

        return res;
    }
};