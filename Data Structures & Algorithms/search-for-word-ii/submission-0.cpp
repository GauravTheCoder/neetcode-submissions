/*
Optimal Algorithm
1. Build a Trie from all words.
- Each Trie node stores children (next letters) and isWord (true if a word ends here).
2. Initialize:
- res as a set (to avoid duplicates).
- visit as a set for the current DFS path.
3. Define DFS dfs(r, c, node, wordSoFar):
1. If (r,c) is out of bounds, already visited, or board[r][c] is not in node.children, stop.
2. Mark (r,c) visited.
3. Move Trie pointer: node = node.children[board[r][c]]
4. Append current char to wordSoFar.
5. If node.isWord == true, add wordSoFar to res.
6. Recurse to 4 neighbors (up/down/left/right) using the updated node and wordSoFar.
7. Backtrack: remove (r,c) from visit.
4. Run DFS starting from every cell (r, c) with the Trie root.
5. Return all collected words from res.
*/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : isWord(false) {}

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visit;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }

        int ROWS = board.size(), COLS = board[0].size();
        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        int ROWS = board.size(), COLS = board[0].size();
        if (r < 0 || c < 0 || r >= ROWS ||
            c >= COLS || visit[r][c] ||
            !node->children.count(board[r][c])) {
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord) {
            res.insert(word);
        }

        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);

        visit[r][c] = false;
    }
};