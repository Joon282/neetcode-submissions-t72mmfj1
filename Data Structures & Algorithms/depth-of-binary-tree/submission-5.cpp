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
 */

class Solution {
    int depth = 0;
public:
    int dfs(TreeNode* node) {
        if (!node){
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        return 1 + std::max(left,right);
    }

    int maxDepth(TreeNode* root) {
        depth = dfs(root);
        return depth;
    }
};
