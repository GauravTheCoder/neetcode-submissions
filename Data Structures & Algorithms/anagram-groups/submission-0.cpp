        class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::map<std::array<int, 26>, std::vector<std::string>> groups;
    
    for (const std::string& s : strs) {
        std::array<int, 26> count = {0};
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        groups[count].push_back(s);
    }
    
    std::vector<std::vector<std::string>> result;
    for (auto& pair : groups) {
        result.push_back(pair.second);
    }
    
    return result;
    }
};
