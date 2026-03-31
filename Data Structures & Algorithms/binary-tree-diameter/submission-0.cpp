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
    int height(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        return 1 + std::max(height(node->left), height(node->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int maxDiameter = left + right;
        int currentNode = std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return std::max(maxDiameter, currentNode);
    }
};
