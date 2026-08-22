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
1. Maintain a global result res, initialized with the root’s value.
2. Define dfs(node):
- If node is None, return 0.
- Recursively compute:
leftMax = dfs(node.left)
rightMax = dfs(node.right)
- Ignore negative downward paths:
leftMax = max(leftMax, 0)
rightMax = max(rightMax, 0)
- Update global result with the best path through node:
res = max(res, node.val + leftMax + rightMax)
- Return the best "extendable" downward path:
node.val + max(leftMax, rightMax)
3. Call dfs(root) and return res.
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }
    private:
        int dfs(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }

        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);

        res = max(res, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }
};
