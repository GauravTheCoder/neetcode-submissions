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
1. Maintain two global indices: preIdx for preorder and inIdx for inorder.
2. Define a recursive function dfs(limit) that builds a subtree until it hits the limit value.
3. If preIdx >= n, return null (no more nodes).
4. If inorder[inIdx] == limit, increment inIdx and return null (subtree complete).
5. Create a root node with preorder[preIdx], increment preIdx.
6. Build the left subtree with dfs(root.val) since nodes less than root appear before it in inorder.
7. Build the right subtree with dfs(limit) using the original limit.
8. Return the root node. Start with dfs(infinity) or a value larger than any node.
 */

class Solution {
    int preIdx = 0;
    int inIdx = 0;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (preIdx >= preorder.size()) return nullptr;
        if (inorder[inIdx] == limit) {
            inIdx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
