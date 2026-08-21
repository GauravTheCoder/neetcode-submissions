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
1. Create an empty list res to store the right-side values.
2. Define a dfs function that takes a node and its depth.
3. In the dfs:
- If the node is null → return.
- If depth == len(res) → this is the first node at this depth → append its value.
- Recursively visit the right child first.
- Then recursively visit the left child.
4. Start dfs from the root at depth 0.
5. Return res.
 */

class Solution {
public:
vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
        void dfs(TreeNode* node, int depth) {
        if (!node) return;

        if (res.size() == depth) {
            res.push_back(node->val);
        }

        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }
};
