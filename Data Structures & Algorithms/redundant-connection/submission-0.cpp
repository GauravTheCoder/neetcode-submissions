/*
Disjoint Set Union Algorithm
1. Initialize DSU where each node is its own parent.
2. For each edge (u, v):
- Find the parent of u and v.
- If both parents are the same:
- Return (u, v) → this edge creates a cycle.
• Otherwise, union the two components.
3. The first edge that cannot be unioned is the redundant edge.
This works because a tree with n nodes has exactly n - 1 edges, and any extra edge must form a cycle.
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1), rank(n + 1, 1);
        for (int i = 0; i <= n; ++i)
            par[i] = i;

        for (const auto& edge : edges) {
            if (!Union(par, rank, edge[0], edge[1]))
                return vector<int>{ edge[0], edge[1] };
        }
        return {};
    }

private:
    int Find(vector<int>& par, int n) {
        int p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool Union(vector<int>& par, vector<int>& rank, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);

        if (p1 == p2)
            return false;
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};