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
1. Maintain an empty list res where res[d] stores all nodes at depth d.
2. Define a recursive function dfs(node, depth):
- If node is null, return.
- If res has no list for this depth, append a new empty list.
- Append the node's value to res[depth].
- Recurse on node.left with depth + 1.
- Recurse on node.right with depth + 1.
3. Call dfs(root, 0).
4. Return res.
 */

class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
        void dfs(TreeNode* node, int depth) {
        if (!node) return;

        if (res.size() == depth) {
            res.push_back(vector<int>());
        }

        res[depth].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};
