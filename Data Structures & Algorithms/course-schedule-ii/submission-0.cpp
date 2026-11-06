/*
Optimal BFS Algorithm
1. Build a directed graph from prerequisites and compute indegree for each course.
2. For every course with indegree = 0, start a DFS.
3. In DFS:
- Add the current course to the result.
- Decrease indegree of its neighbors.
- If any neighbor's indegree becomes 0, recursively DFS on it.
4. After traversal:
- If result contains all courses, return it.
- Otherwise, return an empty list (cycle detected).
*/

class Solution {
    vector<int> output;
    vector<int> indegree;
    vector<vector<int>> adj;

    void dfs(int node) {
        output.push_back(node);
        indegree[node]--;
        for (int nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) {
                dfs(nei);
            }
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        indegree = vector<int>(numCourses, 0);
        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                dfs(i);
            }
        }

        if (output.size() != numCourses) return {};
        return output;
    }
};