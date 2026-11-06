/*
Optimal BFS Algorithm
1. If number of edges > n - 1, return false.
2. Build an adjacency list for the undirected graph.
3. Start bfs from node 0, store (node, parent) in the queue.
4. For each neighbor:
- Ignore the parent.
- If already visited → cycle found → return false.
- Otherwise, mark visited and add to queue.
5. After bfs, check if visited node count equals n.
6. Return true only if no cycle and all nodes are visited.
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visit;
        queue<pair<int, int>> q;
        q.push({0, -1});  // {current node, parent node}
        visit.insert(0);

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for (int nei : adj[node]) {
                if (nei == parent) {
                    continue;
                }
                if (visit.count(nei)) {
                    return false;
                }
                visit.insert(nei);
                q.push({nei, node});
            }
        }

        return visit.size() == n;
    }
};