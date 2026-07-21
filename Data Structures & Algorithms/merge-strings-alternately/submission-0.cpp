class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int len1 = word1.length();
        int len2 = word2.length();
        result.reserve(len1+len2);
        int p1{}, p2{};
        while(p1<len1 && p2<len2) {
            result.push_back(word1[p1++]);
            result.push_back(word2[p2++]);
        }
        if(p1<len1) {
            result.append(word1, p1, len1-p1);
        }
        if(p2<len2) {
            result.append(word2, p2, len2-p2);
        }
        return result;
    }
};