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
    bool isBalanced(TreeNode* root) {
        if (!root){
            return true;
        }
        int height = 1;
        int left = getHeight(root->left, height);
        int right = getHeight(root->right, height);
        if (std::abs(right - left) > 1){
            return false;
        }
        return true;
    }
    int getHeight(TreeNode* node, int& height){
        if (!node){
            return 0;
        }
        int left = getHeight(node->left, height);
        int right = getHeight(node->right, height);
        height = std::max(left + right, height);
        return 1 + std::max(left,right);
    }
};
