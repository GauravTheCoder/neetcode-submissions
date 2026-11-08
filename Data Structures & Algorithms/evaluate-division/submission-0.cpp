/*
DSU Algorithm
1. Initialize parent and weight maps. Each variable starts as its own parent with weight 1.0.
2. The find operation uses path compression: while finding the root, update the weight to be relative to the root by multiplying along the path.
3. The union operation connects two variables: find both roots, and if different, set one root's parent to the other and adjust the weight to maintain the given ratio.
4. Process all equations by calling union for each pair.
5. For each query (x, y):
- If either variable is unknown or they have different roots, return -1.
- Otherwise, return weight[x] / weight[y].
*/

class UnionFind {
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

public:
    void add(const string& x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            weight[x] = 1.0;
        }
    }

    string find(const string& x) {
        if (x != parent[x]) {
            string origParent = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origParent];
        }
        return parent[x];
    }

    void unionSets(const string& x, const string& y, double value) {
        add(x);
        add(y);
        string rootX = find(x);
        string rootY = find(y);

        if (rootX != rootY) {
            parent[rootX] = rootY;
            weight[rootX] = value * weight[y] / weight[x];
        }
    }

    double getRatio(const string& x, const string& y) {
        if (parent.find(x) == parent.end() || parent.find(y) == parent.end() || find(x) != find(y)) {
            return -1.0;
        }
        return weight[x] / weight[y];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionFind uf;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            uf.unionSets(a, b, values[i]);
        }

        vector<double> result;
        for (const auto& query : queries) {
            string a = query[0];
            string b = query[1];
            result.push_back(uf.getRatio(a, b));
        }

        return result;
    }
};