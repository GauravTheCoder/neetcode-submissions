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
1. Start DFS from the root with the initial valid range (-∞, +∞).
2. For each node:
- If node.val is not strictly between (left, right) → return false.
3. Recursively:
- Validate the left subtree with updated range (left, node.val).
- Validate the right subtree with updated range (node.val, right).
4. If all nodes satisfy their ranges → it is a valid BST.
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
        bool valid(TreeNode* node, long left, long right) {
        if (!node) {
            return true;
        }
        if (!(left < node->val && node->val < right)) {
            return false;
        }
        return valid(node->left, left, node->val) &&
               valid(node->right, node->val, right);
    }
};
