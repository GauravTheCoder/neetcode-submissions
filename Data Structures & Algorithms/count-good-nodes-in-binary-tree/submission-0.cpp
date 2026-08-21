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
1. Start DFS from the root and store the root's value as the current maxSoFar.
2. At each node:
- If node.val >= maxSoFar, count it as a good node.
- Update maxSoFar = max(maxSoFar, node.val).
3. Recursively explore:
- Left child with updated maxSoFar
- Right child with updated maxSoFar
4. Sum the counts from left and right and return the total.
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* node, int maxVal) {
        if (!node) {
            return 0;
        }

        int res = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal, node->val);
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);
        return res;
    }
};
