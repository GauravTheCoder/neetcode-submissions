class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded = "";
        for (const std::string& s : strs) {
            encoded += std::to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded;
        size_t i = 0;
        
        while (i < s.length()) {
            size_t j = s.find('#', i);
            
            int len = std::stoi(s.substr(i, j - i));
            
            i = j + 1;
            
            decoded.push_back(s.substr(i, len));
            
            i += len;
        }
        
        return decoded;
    }
};
