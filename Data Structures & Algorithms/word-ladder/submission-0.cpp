/*
BFS-3 Algorithm
1. For each word in the list (including beginWord), generate patterns by replacing each character with '*' and group words by these patterns.
2. Start BFS from beginWord, maintaining a visited set.
3. For the current word, generate its patterns and look up all words in corresponding pattern buckets.
4. Add unvisited neighbors to the queue and mark them visited.
5. Return the level count when endWord is reached, or 0 if unreachable.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);
        for (const string& word : wordList) {
            for (int j = 0; j < word.size(); ++j) {
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                nei[pattern].push_back(word);
            }
        }

        unordered_set<string> visit{beginWord};
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return res;
                }
                for (int j = 0; j < word.size(); ++j) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (const string& neiWord : nei[pattern]) {
                        if (visit.find(neiWord) == visit.end()) {
                            visit.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};