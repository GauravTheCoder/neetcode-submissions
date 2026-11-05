/*
Optimal BFS Algorithm
1. Handle edge cases for target "0000" and "0000" being a deadend.
2. Create two sets: begin starting from "0000" and end starting from target.
3. While both sets are non-empty:
- If begin is larger than end, swap them to always expand the smaller one.
- Increment steps and create a temporary set for the next level.
- For each state in begin, generate all 8 neighbors.
- If a neighbor is in end, the frontiers meet, so return steps.
- Otherwise, if unvisited, add to the temp set and mark visited.
- Replace begin with the temp set.
4. Return -1 if the sets never meet.
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;

        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;

        unordered_set<string> begin = {"0000"}, end = {target};
        int steps = 0;

        while (!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) swap(begin, end);
            steps++;
            unordered_set<string> temp;

            for (const string& lock : begin) {
                for (int i = 0; i < 4; ++i) {
                    for (int j : {-1, 1}) {
                        string nextLock = lock;
                        nextLock[i] = (nextLock[i] - '0' + j + 10) % 10 + '0';

                        if (end.count(nextLock)) return steps;
                        if (visit.count(nextLock)) continue;

                        visit.insert(nextLock);
                        temp.insert(nextLock);
                    }
                }
            }
            begin = temp;
        }
        return -1;
    }
};