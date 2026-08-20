/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
Recursive Algorithm
1. Use DFS to compute the height of every subtree.
2. For each node during DFS:
- Recursively get left height.
- Recursively get right height.
- Diameter through this node = left + right.
- Update the global answer with this diameter.
3. Height returned to parent = 1 + max(left, right).
4. After DFS finishes, the global answer contains the diameter.
This gives an O(n) time solution with a single DFS traversal.
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    private:
        int dfs(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);
        return 1 + max(left, right);
    }
};
