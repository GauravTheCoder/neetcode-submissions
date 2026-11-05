/*
Topological Sort  Algorithm
1. Build a graph and compute indegree (number of prerequisites) for each course.
2. Add all courses with indegree = 0 into a queue.
3. While the queue is not empty:
- Remove a course from the queue.
- Mark it as finished.
- Reduce the indegree of its dependent courses.
- If any dependent course reaches indegree = 0, add it to the queue.
4. After processing:
- If finished courses == total courses - return true
- Else - return false
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return finish == numCourses;
    }
};