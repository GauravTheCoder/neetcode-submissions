class Solution {
private:
    bool isPalindromeRange(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left{0}, right{static_cast<int>(s.length())-1};
        while(left<right) {
            if(s[left] != s[right]) {
                return isPalindromeRange(s, left+1, right) || isPalindromeRange(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};