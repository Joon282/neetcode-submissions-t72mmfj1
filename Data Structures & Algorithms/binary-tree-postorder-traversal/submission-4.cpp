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
    std::vector<int> results;
public:
    void dfs(TreeNode* node){
        if (!node){
            return;
        }
        dfs(node->left);
        dfs(node->right);
        results.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return results;
    }
};