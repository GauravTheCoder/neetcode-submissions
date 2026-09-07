/*
Optimal Algorithm
1. Build a Trie by inserting all words from the dictionary.
2. Use backtracking starting at index 0 with an empty path.
3. At each position, traverse the Trie character by character from the current index.
4. When reaching a node marked as a word end, add that word to the path and recurse on the remaining string.
5. If a character is not found in the Trie, stop exploring that branch early.
6. When index reaches the end, join the path and add to results. Backtrack by removing the last word.
*/
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (const string& word : wordDict) {
            trie.addWord(word);
        }

        vector<string> res;
        vector<string> path;
        backtrack(0, s, path, trie, res);
        return res;
    }

private:
    void backtrack(int index, string& s, vector<string>& path, Trie& trie, vector<string>& res) {
        if (index == s.size()) {
            stringstream ss;
            for (int i = 0; i < path.size(); ++i) {
                if (i > 0) ss << " ";
                ss << path[i];
            }
            res.push_back(ss.str());
            return;
        }

        TrieNode* node = trie.root;
        string word;
        for (int i = index; i < s.size(); ++i) {
            char c = s[i];
            if (!node->children.count(c)) break;

            word.push_back(c);
            node = node->children[c];

            if (node->isWord) {
                path.push_back(word);
                backtrack(i + 1, s, path, trie, res);
                path.pop_back();
            }
        }
    }
};
