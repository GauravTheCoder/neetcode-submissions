/*
Optimal Solution
1. Count the frequency of each character in s1 using a fixed-size frequency array of size 26.
2. Use a sliding window of fixed length equal to s1 over s2.
3. Initialize the first window in s2 from index 0 to s1.length() - 1 and record the character frequencies.
4. Compare the frequency array of the current s2 window with the s1 frequency array.
5. Slide the window one character to the right by adding the new character and removing the leftmost character from the s2 frequency counts.
6. Return true if the frequency counts match at any point, and false if the loop finishes without a match.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1{static_cast<int>(s1.length())};
        int n2{static_cast<int>(s2.length())};
        if (n1 > n2) return false;
        std::vector<int> count1(26, 0);
        std::vector<int> count2(26, 0);
        for (int i{0}; i < n1; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        if (count1 == count2) return true;
        for (int i{n1}; i < n2; ++i) {
            count2[s2[i] - 'a']++;
            count2[s2[i - n1] - 'a']--;
            if (count1 == count2) return true;
        }
        return false;
    }
};
