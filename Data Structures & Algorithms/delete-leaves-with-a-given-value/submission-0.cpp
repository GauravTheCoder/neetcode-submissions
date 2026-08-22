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
1. If the root is null, return null.
2. Recursively process the left subtree and update root.left with the result.
3. Recursively process the right subtree and update root.right with the result.
4. After processing children, check if the current node is now a leaf (both children null) and has the target value. If so, return null to delete it.
5. Otherwise, return the root.
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }
        return root;
    }
};