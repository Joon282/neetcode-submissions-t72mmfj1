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
public:
    int dfs(TreeNode* node, int val){
        if (!node){
            return 0;
        }
        int result;
        if (node->val >= val){
            result = 1;
        } else {
            result = 0;
        }
        val = std::max(val, node->val);
        if (node->left) {
            result += dfs(node->left, val);
        }
        if (node->right){
            result += dfs(node->right, val);
        }
        return result;
    }
    int goodNodes(TreeNode* root) {
        if (!root){
            return 0;
        }
        int count = dfs(root, root->val);
        return count;
    }
};
