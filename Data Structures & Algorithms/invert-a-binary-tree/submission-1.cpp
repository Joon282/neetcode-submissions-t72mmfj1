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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return nullptr;
        }
        std::stack<TreeNode*> stack1;
        TreeNode* node = root;
        stack1.push(root);
        while (!stack1.empty()){
            node = stack1.top();
            stack1.pop();
            std::swap(node->left, node->right);
            if (node->left != nullptr){
                stack1.push(node->left);
            }
            if (node->right != nullptr){
                stack1.push(node->right);
            }
        }
        return root;
    }
};
