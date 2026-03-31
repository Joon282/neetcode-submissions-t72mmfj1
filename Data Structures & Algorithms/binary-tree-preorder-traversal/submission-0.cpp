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
    void traverse(TreeNode* node){
        if (node == nullptr){
            return;
        }
        results.push_back(node->val);
        traverse(node->left);
        traverse(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return results;
    }
};