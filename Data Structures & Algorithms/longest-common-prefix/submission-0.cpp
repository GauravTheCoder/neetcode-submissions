class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (strs.empty()) return "";
        
        std::sort(strs.begin(), strs.end());
        
        const std::string& first = strs.front();
        const std::string& last = strs.back();
        
        int i = 0;
        int min_len = std::min(first.length(), last.length());
        
        while (i < min_len && first[i] == last[i]) {
            ++i;
        }
        
        return first.substr(0, i);
    }
};