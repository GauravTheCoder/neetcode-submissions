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
2. If the key is greater than the root's value, recursively delete from the right subtree.
3. If the key is less than the root's value, recursively delete from the left subtree.
4. If the key matches the root's value:
- If there is no left child, return the right child.
- If there is no right child, return the left child.
- Otherwise, find the in-order successor (leftmost node in the right subtree), attach the deleted node's left subtree to this successor's left, delete the node, and return the right subtree.
5. Return the root.
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            cur->left = root->left;
            TreeNode* res = root->right;
            delete root;
            return res;
        }
        return root;
    }
};