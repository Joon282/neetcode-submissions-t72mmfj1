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
    bool isValidBST(TreeNode* root) {
        if (!root){
            return true;
        }
        int val = root->val;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (left && left->val > val){
            return false;
        }
        if (right && right->val < val){
            return false;
        }
        return isValidBST(left) && isValidBST(right);
    }
};
