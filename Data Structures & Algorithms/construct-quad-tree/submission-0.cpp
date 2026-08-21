/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
Optimized Algorithm
1. Create two shared leaf nodes: one for false and one for true.
2. Define dfs(n, r, c) as before.
3. Base case: if n == 1, return the appropriate shared leaf node based on grid[r][c].
4. Recursively build the four quadrants.
5. If all four children are leaves with the same value, return one of the children (they point to the same shared node).
6. Otherwise, return a new non-leaf node with the four children.
*/

class Solution {
private:
    Node* falseLeaf = new Node(false, true);
    Node* trueLeaf = new Node(true, true);
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
private:
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
        if (n == 1) {
            return grid[r][c] == 1 ? trueLeaf : falseLeaf;
        }

        n /= 2;
        Node* topLeft = dfs(grid, n, r, c);
        Node* topRight = dfs(grid, n, r, c + n);
        Node* bottomLeft = dfs(grid, n, r + n, c);
        Node* bottomRight = dfs(grid, n, r + n, c + n);

        if (topLeft->isLeaf && topRight->isLeaf &&
            bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topLeft->val == bottomLeft->val &&
            topLeft->val == bottomRight->val) {
            return topLeft;
        }

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};