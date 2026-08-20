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
1. If subRoot is empty → return true (empty tree is always a subtree).
2. If root is empty but subRoot is not → return false.
3. At the current root node:
- If sameTree(root, subRoot) is true, return true.
4. Recursively check:
- isSubtree(root.left, subRoot)
- isSubtree(root.right, subRoot)
5. Return true if either side returns true.
sameTree(root1, root2):
1. If both nodes are null → return true.
2. If only one is null → return false.
3. If values differ → return false.
4. Recursively check left children and right children.
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
        bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (root && subRoot && root->val == subRoot->val) {
            return sameTree(root->left, subRoot->left) &&
                   sameTree(root->right, subRoot->right);
        }
        return false;
    }
};
