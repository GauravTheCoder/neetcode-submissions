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
1. Keep a counter cnt = k.
2. Perform an inorder DFS:
- Go left.
- If cnt == 0, return early (answer already found).
- Decrease cnt.
- If cnt == 0, record this node's value (this is the k-th smallest).
- Go right only if the answer has not been found yet.
3. Return the recorded value.
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tmp(2);
        tmp[0] = k;
        dfs(root, tmp);
        return tmp[1];
    }
        void dfs(TreeNode* node, vector<int>& tmp) {
        if (!node) return;

        dfs(node->left, tmp);
        if (tmp[0] == 0) return;

        tmp[0]--;
        if (tmp[0] == 0) {
            tmp[1] = node->val;
            return;
        }

        dfs(node->right, tmp);
    }
};
