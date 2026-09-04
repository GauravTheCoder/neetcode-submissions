/*
Backtracking Algorithm
1. Maintain:
- part: current list of chosen substrings.
- res: all palindrome partitions.
2. Define DFS dfs(i) where i is the start index of the next substring.
3. Base case:
- If i == len(s), the whole string has been partitioned → add a copy of part to res.
4. For each j from i to len(s)-1:
- If s[i..j] is palindrome:
- Add s[i..j] to part.
- Recurse dfs(j + 1).
- Backtrack: remove last substring.
5. Palindrome check:
- Two pointers l, r move inward; if mismatch → return false.
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        dfs(0, s, part, res);
        return res;
    }
    private:
    void dfs(int i, const string& s, vector<string>& part, vector<vector<string>>& res) {
        if (i >= s.length()) {
            res.push_back(part);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (isPali(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, part, res);
                part.pop_back();
            }
        }
    }

    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
