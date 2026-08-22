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
DP Optimal Algorithm
1. Define a recursive function that returns a pair: [maxWithNode, maxWithoutNode].
2. For a null node, return [0, 0].
3. Recursively get the pairs for left and right children.
4. Calculate withRoot as the node's value plus leftPair[1] plus rightPair[1] (children must be skipped).
5. Calculate withoutRoot as max(leftPair) plus max(rightPair) (children can be robbed or skipped).
6. Return [withRoot, withoutRoot].
7. The final answer is the maximum of the two values returned for the root.
 */
class Solution {
public:
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
    private:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto leftPair = dfs(root->left);
        auto rightPair = dfs(root->right);

        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first, leftPair.second) +
                          max(rightPair.first, rightPair.second);

        return {withRoot, withoutRoot};
    }
};